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
    bool check_ustar = 0;
    do
    {
        read_header();
        for (i = 0; i < 11; i++)
            size_dec += (int(header[header.size() - 1].filesize[i]) - 48) * pow(8, 10 - i);

        if (size_dec / 512 == size_dec / 512.0)
            jump = size_dec / 512;
        else
            jump = size_dec / 512 + 1;
        size_dec = 0;

        if (!check_ustar) //check ustar
        {
            char ustar[6] = "ustar";
            for (int i = 0; i < 5; i++)
            {
                if (header[0].USTAR_id[i] != ustar[i])
                {
                    cout << "Not ustar format." << endl;
                    exit(0);
                }
            }
            check_ustar = 1;
        }

    } while (inputStream.seekg(512 * jump, inputStream.cur));
    return;
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
    
    /*
        cout << "filename:\t" << tempHeader.filename << endl;
        cout << "filemode:\t" << tempHeader.filemode << endl;
        cout << "userid:\t\t" << tempHeader.userid << endl;
        cout << "groupid:\t" << tempHeader.groupid << endl;
        cout << "filesize:\t" << tempHeader.filesize << endl;
        cout << "mtime:\t\t" << tempHeader.mtime << endl;
        cout << "checksum:\t" << tempHeader.checksum << endl;
        cout << "type:\t\t" << tempHeader.type << endl;
        cout << "lname:\t" << tempHeader.lname << endl;
        cout << "USTAR_id:\t" << tempHeader.USTAR_id << endl;
        cout << "USTAR_ver:\t" << tempHeader.USTAR_ver << endl;
        cout << "username:\t" << tempHeader.username << endl;
        cout << "groupname:\t" << tempHeader.groupname << endl;
        cout << "devmajor:\t" << tempHeader.devmajor << endl;
        cout << "devminor:\t" << tempHeader.devminor << endl;
        cout << "prefix:\t" << tempHeader.prefix << endl;
        cout << "pad:\t" << tempHeader.pad << endl<<endl;
    */
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
        int tmp_size = 0;
        for (j = 0; j < 11; j++)
            tmp_size += (int(header[i].filesize[j]) - 48) * pow(8, 10 - j);
        cout << setw(6) << tmp_size << " ";

        //file time
        int tmp_time = 0;
        for (j = 0; j < 11; j++)
            tmp_time += (int(header[i].mtime[j]) - 48) * pow(8, 10 - j);
        cout << read_time(tmp_time) << " ";

        //file names
        cout << header[i].filename;

        cout << endl;
    }
    return;
}