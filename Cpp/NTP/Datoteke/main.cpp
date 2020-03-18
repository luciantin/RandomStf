#include <iostream>
#include <fstream>


using namespace std;


int main(){

    // ofstream - upis u dat   (output iz prog) (ios_base::out) (tellp | seekp)
    // ifstream - ispis iz dat (input u prog)   (ios_base::in)  (tellg | seekg)


    fstream fileF;
    fstream fileE;

    char* filename = new char[30];
    char* strData = new char[30];
    char tmpCh;

    streampos crntPos;

    fileF.open(("front.txt"), ios_base::in | ios_base::ate);
    fileE.open(("end.txt"),   ios_base::out | ios_base::trunc);

    crntPos = fileF.tellg();

    do{
    crntPos = crntPos -1;
    fileF.seekg(crntPos);
    fileE.put(fileF.get());
    }while((int)crntPos > 0);  


    fileF.close();
    fileE.close();
    return 0;
}