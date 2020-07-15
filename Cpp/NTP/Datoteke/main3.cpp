#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// ofstream - upis u dat   (output iz prog) (ios_base::out) (tellp | seekp)
// ifstream - ispis iz dat (input u prog)   (ios_base::in)  (tellg | seekg)


struct Kontakt{
  char ime[30];
  char tel[12];
  char addr[30];
  char mail[30];
};


int main() {

/*Zadatak 1
Neka se u binarnoj datoteci nalazi slijedeći niz znakova:
ABCDEFGHIJKLMNOPQRSTUVWXYZ
Napišite program koji će ispisati na ekran vaše ime čitajući i ispisujući odgovarajuća slova iz datoteke.*/

string Ime = "TEST";

	ifstream fajl ("bin.txt", ios::in|ios::binary);

	if (fajl.is_open()){
    for(int i = 0; i< Ime.length();i++ ){
      fajl.seekg (Ime[i]-65, ios::beg);
      char* slovo = new char;
      fajl.read(slovo,sizeof(char));
      cout<<*slovo<<endl;
    }		
		fajl.close();
	}
	else cout << "Greska u otvaranju datoteke";

/*Zadatak 2
Napišite program koji će sva podatke iz datoteke postbrojevi.txt u kojoj se nalaze poštanski brojevi i nazivi svih mjesta u Hrvatskoj prepisati u odgovarajuću binarnu datoteku postbrojevi.dat  (vodite računa o širini char polja za naziv mjesta).*/



	ifstream fajl2I ("postbrojevi.txt", ios::in|ios::binary|ios_base::ate);
	ofstream fajl2O ("postbrojevi.dat", ios::out|ios::binary);



	if (fajl2I.is_open()){
    streampos vel = fajl2I.tellg();
    char* polje = new char[vel];    
    fajl2I.seekg (0, ios::beg);
    fajl2I.read(polje, vel);
    fajl2O.write(polje, vel);
		fajl2I.close();
    fajl2O.close();
	}
	else cout << "Greska u otvaranju datoteke";



/*Zadatak 3
Napišite program koji pretražuje datoteku postbrojevi.dat. Na osnovu upisnog poštanskog broja program treba u datoteci pronaći i ispisati odgovarajući naziv mjesta sa upisanim poštanskim brojem.*/

ifstream fajl3I ("postbrojevi.dat", ios::in|ios::binary);

string posBr = "52210";
char tmpBr[10];
char tmpBr2[10]={'2','2','3','0','0'};
char tmpGrad[50];
// 22300 Knin
if (fajl3I.is_open()){
    while(!fajl3I.eof()){
      fajl3I.getline(tmpBr,6,' ');
      fajl3I.getline(tmpGrad,50,'\n');
    //   cout<<tmpBr<<"  "<<tmpGrad;
      if(strcmp(tmpBr2,tmpBr)==0) cout<<tmpGrad<<"asdasd";
    }

    fajl3I.close();
	}
else cout << "Greska u otvaranju datoteke";


/*Zadatak 4
Napisati program koji služi za vođenje kontakata (u datoteci) i sadrži strukturu kontakt. Program preko izbornika treba omogućiti :
Ispisivanje svih kontakata
Dodavanje novog kontakta
Pretraživanje kontakata po imenu
Kontakt se sastoji od imena, adrese, broja telefona, email adrese. Sve se operacije izvode preko izbornika.*/

// fstream KontaktDat ("Kontakti.dat",ios_base::in| ios_base::out | ios_base::binary);

// Kontakt *A = new Kontakt;

// cout<<"Unesi KOntakt"<<endl;
// strcpy(A->ime,"Ime2");
// strcpy(A->tel,"tel2");
// strcpy(A->mail,"mail2");

// KontaktDat.write((char*)A,sizeof(Kontakt));


// ifstream KontaktDat2 ("Kontakti.dat", ios::in | ios::binary);

// Kontakt *B = new Kontakt;


// KontaktDat2.seekg(0,ios_base::beg);
// KontaktDat2.read((char*)B,sizeof(Kontakt));

// cout<<B->ime<<endl<<B->tel<<endl<<B->mail;


}