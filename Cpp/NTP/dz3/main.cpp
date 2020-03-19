#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct tstudent{
int mat_br;
char prez_ime[35];
int g_stu;
};

tstudent student;  
fstream dat; 
char naziv_datoteke[40]; 



void kreiranje_datoteke(){
    char promjena;
    cout<< "Unesite naziv datoteke u koju cete spremati podatke : ";
    cin>> naziv_datoteke;
    dat.open(naziv_datoteke,ios::in | ios::binary);
    if (!dat){ 
    dat.open(naziv_datoteke,ios::out | ios::binary); 
    dat.close();
    dat.clear();
    }
    else{ 
        cout<< "Datoteka " << naziv_datoteke<< " vec postoji na disku."<<endl;
        dat.close();
        dat.clear();
    } //else
};

void unos(char *znakovni_niz){
    cin.getline(znakovni_niz, 150);
    if (cin.gcount()==1)cin.getline (znakovni_niz,150);
};

void unos_podataka_u_datoteku(){
    char dalje;
    dat.open(naziv_datoteke,ios::out|ios::ate  |ios::binary); //| ios::nocreate nema vise

    do{
        cout<<"Maticni broj:";
        cin>>student.mat_br;
        cout<<"Prezime i ime:";
        unos(student.prez_ime);
        cout<<"Godina studija:";
        cin>>student.g_stu;
        dat.write((char*)&student,sizeof(student));
        cout<<"Dalje?(d/n)";cin>>dalje;
    }while(dalje=='d');

    dat.close();
    dat.clear();
}

void ispis_podataka_o_svim_studentima(){
    dat.open(naziv_datoteke,ios::in | ios::binary);
    while (1){
        dat.read((char *) &student,sizeof(student));
        if (dat.eof()) break;
        cout << "Maticni broj: " << student.mat_br << endl;
        cout << "Prezime i ime: " << student.prez_ime << endl;
        cout << "Godina studija: " << student.g_stu << endl;
    }
    dat.close();
    dat.clear();
}

void ispis_podataka_o_zadanom_studentu(int mb){
    int brojac=0;
    dat.open(naziv_datoteke,ios::in | ios::binary);
    while (1){
        dat.read((char *) &student,sizeof(student));
        if (dat.eof()) break;
        if (student.mat_br==mb){
            cout<< "Maticni broj: " << student.mat_br<< endl;
            cout<< "Prezime i ime: " << student.prez_ime<< endl;
            cout<< "Godina studija: " << student.g_stu<< endl;
            brojac++;
            }
        }
        if (brojac==0)cout<< "Student s maticnim brojem" << mb<< " nije nadjenu datoteci."<<endl;
        dat.close();
        dat.clear();
};

void sort_ispis_podataka_o_svim_studentima(const int izbor){
    vector< pair<int, string> > popisSt;
    string tmpIme;
    streampos tmpPos;

    dat.open(naziv_datoteke,ios::in | ios::binary);
    while (1){
        tmpPos = dat.tellg();
        dat.read((char *) &student,sizeof(student));
        if (dat.eof()) break;

        string ime = student.prez_ime;
        if(izbor == 1) tmpIme = ime.substr(0,ime.find_first_of(" ",0)); // ime 
        else if(izbor == 2)tmpIme = ime.substr(ime.find_first_of(" ",0) + 1,ime.size() - ime.find_first_of(" ",0) ); // prezime
        else if(izbor == 3)tmpIme = ime; // oba

        popisSt.push_back( make_pair((int)tmpPos,tmpIme));
    }

    sort(popisSt.begin(),popisSt.end(),[]
        (const pair< int,string > &a,const pair< int,string > &b){
             return a.second > b.second;
        });

    // ispis vec
    // for(int i=0; i<popisSt.size(); ++i) cout << popisSt[i].second << ' '<<popisSt[i].first<<endl; 

    cout<<"-----------------------------------"<<endl;
    for(int i=0; i<popisSt.size(); ++i) {
        dat.clear();
        dat.seekg(popisSt[i].first);
        dat.read((char *) &student,sizeof(student));
        cout<< "Maticni broj: " << student.mat_br<< endl;
        cout<< "Prezime i ime: " << student.prez_ime<< endl;
        cout<< "Godina studija: " << student.g_stu<< endl;
        cout<<"-----------------------------------"<<endl;
    }

    dat.close();
    dat.clear();
}


int main(){
    int izbor,mbr;
    do{
        cout<<"Izaberite:" <<endl<<endl;
        cout<<"1. Kreiranje datoteke"<<endl;        
        cout<<"2. Unos podataka u datoteku"<<endl;
        cout<<"3. Ispis svih zapisa iz datoteke "<<endl;
        cout<<"4. Ispis podataka o zadanom studentu"<<endl;
        cout<<"5. Sortirani ispis svih zapisa iz datoteke "<<endl;
        cout<<"9. Izlaz iz programa"<<endl;
        cin>> izbor;
        switch (izbor){
            case 1:
            kreiranje_datoteke();
            break;
            case 2:
            unos_podataka_u_datoteku();
            break;
            case 3:
            ispis_podataka_o_svim_studentima();
            break;
            case 5:
            cout<<"sort po Ime : 1"<<endl<<"sort po Prezime : 2 "<<endl<<"sort po Ime i Prezime : 3"<<endl<<" : ";
            cin>>izbor;
            sort_ispis_podataka_o_svim_studentima(izbor);
            break;
            case 4:
            cout << "Maticni broj studenta:";
            cin>> mbr;
            ispis_podataka_o_zadanom_studentu(mbr);
            break;
            }
    } while (izbor!= 9);
return 1;}