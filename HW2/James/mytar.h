#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <sstream>
using namespace std;

struct TarHeader
{
    char filename[100];
    char filemode[8];
    char userid[8];
    char groupid[8];
    char filesize[12];
    char mtime[12];
    char checksum[8];
    char type;
    char lname[100];

    /* USTAR Section */
    char USTAR_id[6];
    char USTAR_ver[2];
    char username[32];
    char groupname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char pad[12];
};

class mytar
{
public:
    ifstream inputStream;
    vector<TarHeader> header;
    mytar(const char *file);
    void start_read();
    void read_header();
    void print();
    string read_time(int time_);
    string read_mode(int num);
    bool check_ustar(TarHeader check);
    int ocl_to_dec(char *s);
};