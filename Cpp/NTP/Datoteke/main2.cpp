#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct tstudent{
    int id;
    char ime[5];
    float ocjena;
};

int main(){

// ofstream - upis u dat   (output iz prog) (ios_base::out) (tellp | seekp)
// ifstream - ispis iz dat (input u prog)   (ios_base::in)  (tellg | seekg)


    fstream dat;
    char cj = 'd';

    tstudent* st;

    dat.open("new.bin", ios_base::out | ios_base::binary |ios_base::in | ios_base::trunc);

    if(!dat) return -1;

    for(int i= 0;i<10;i++){
        st = new tstudent;
        st->id = i;
        strcpy(st->ime,"dasv<");
        st->ocjena = 2.3;
        dat.write((char*)&(*st),sizeof((*st)));
    }

    dat.seekg(0,ios_base::beg);

    tstudent tm;
    dat.read((char*)&tm,sizeof(tstudent));

    cout<<tm.id<<tm.ime<<endl;


    dat.close();
    return 0;
}