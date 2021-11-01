#include "mytar.h"
mytar::mytar(const char *file)
{
    this->usBlockSize = 512;  /// Every block in USTAR format is 512 bytes.
    this->fileNum = -1;
    this->inputStream.open(file, ifstream::in | ifstream::binary);

    /// If failed, close the program.
    if(!this->inputStream.is_open())
    {
        cout << "Open failed!" << endl;
        exit(0);
    }
}
 
int mytar::startRead()
{
    for(int i=0 ; i<100 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<1 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<100 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<6 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<2 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<32 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<32 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<155 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
/////////////////////////////////////////////////////////////
    char tmp;
    int count = 0;
    while(this->inputStream.get(tmp))
    {
        //cout<<tmp;
        count++;
        if(count==512) break;
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~count="<<count<<endl;
//////////////////////////////////////////////////////////////
    for(int i=0 ; i<100 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<1 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<100 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<6 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<2 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<32 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<32 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<155 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
 ///////////////////////////////////////////////////////////   
    count = 0;
    while(this->inputStream.get(tmp))
    {
        count++;
        if(count==1024) break;
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~count="<<count<<endl;
///////////////////////////////////////////////////////////    
    for(int i=0 ; i<100 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<1 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<100 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<6 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<2 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<32 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<32 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<8 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<155 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
    for(int i=0 ; i<12 ; i++)
    {
        char ch;
        this->inputStream.get(ch);
        cout<<ch;
    }
    cout<<endl;
 ///////////////////////////////////////////////////////////   
    count = 0;
    while(this->inputStream.get(tmp))
    {
        count++;
        if(count==512) break;
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~count="<<count<<endl;
///////////////////////////////////////////////////////////
    return 1;
}