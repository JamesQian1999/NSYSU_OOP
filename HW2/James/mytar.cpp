#include "mytar.h"
mytar::mytar(const char *file)
{
    inputStream.open(file, ifstream::in | ifstream::binary);

    if (!inputStream.is_open())
    {
        cout << "mytar: " << file << ": Cannot open: No such file or directory" << endl;
        exit(0);
    }
}

void mytar::start_read()
{
    int i, size_dec = 0, jump;
    bool checked = 0;
    do
    {
        read_header();
        size_dec = ocl_to_dec(header[header.size() - 1].filesize);

        if (size_dec / 512 == size_dec / 512.0)
            jump = size_dec / 512;
        else
            jump = size_dec / 512 + 1;
        size_dec = 0;

        if (!checked) //check ustar
            checked = check_ustar(header[0]);

    } while (inputStream.seekg(512 * jump, inputStream.cur));
    return;
}

bool mytar::check_ustar(TarHeader check)
{
    char ustar[6] = "ustar";
    for (int i = 0; i < 5; i++)
    {
        if (check.USTAR_id[i] != ustar[i])
        {
            cout << "Not ustar format." << endl;
            exit(0);
        }
    }
    return 1;
}

void mytar::read_header()
{
    struct TarHeader tempHeader;
    inputStream.read(tempHeader.filename, 100);
    inputStream.read(tempHeader.filemode, 8);
    inputStream.read(tempHeader.userid, 8);
    inputStream.read(tempHeader.groupid, 8);
    inputStream.read(tempHeader.filesize, 12);
    inputStream.read(tempHeader.mtime, 12);
    inputStream.read(tempHeader.checksum, 8);
    inputStream.read(&tempHeader.type, 1);
    inputStream.read(tempHeader.lname, 100);
    inputStream.read(tempHeader.USTAR_id, 6);
    inputStream.read(tempHeader.USTAR_ver, 2);
    inputStream.read(tempHeader.username, 32);
    inputStream.read(tempHeader.groupname, 32);
    inputStream.read(tempHeader.devmajor, 8);
    inputStream.read(tempHeader.devminor, 8);
    inputStream.read(tempHeader.prefix, 155);
    inputStream.read(tempHeader.pad, 12);

    header.push_back(tempHeader);
}

string mytar::read_time(int time_)
{
    time_t tmp = time_ + 28800; //UTF+8
    tm *t = gmtime(&tmp);
    stringstream ss;
    ss << put_time(t, "%Y-%m-%d %H:%M");
    string ans = ss.str();
    return ans;
}

int mytar::ocl_to_dec(char *s)
{
    int ans = 0;
    for (int i = 0; i < 11; i++)
        ans += (int(s[i]) - 48) * pow(8, 10 - i);
    return ans;
}

void mytar::print()
{
    int i, j, k, mode;
    bool mode_select[3];
    char rwx[3] = {'r', 'w', 'x'};
    for (i = 0; i < header.size() - 1; i++)
    {
        //mode
        if (header[i].type == '5')
            cout << 'd';
        else
            cout << '-';

        for (j = 4; j < 7; j++)
        {
            for (k = 0; k < 3; k++)
                mode_select[k] = 0;

            mode = int(header[i].filemode[j]) - '0';
            if (mode >= 4)
            {
                mode_select[0] = 1;
                mode -= 4;
            }
            if (mode >= 2)
            {
                mode_select[1] = 1;
                mode -= 2;
            }
            if (mode)
            {
                mode_select[2] = 1;
            }

            for (k = 0; k < 3; k++)
            {
                if (mode_select[k])
                    cout << rwx[k];
                else
                    cout << '-';
            }
        }

        //username, groupname
        cout << " " << header[i].username << "/" << header[i].groupname << " ";

        //file size
         cout << setw(6) << ocl_to_dec(header[i].filesize) << " ";

        //file time
        cout << read_time(ocl_to_dec(header[i].mtime)) << " ";

        //file names
        cout << header[i].filename;

        cout << endl;
    }
    return;
}