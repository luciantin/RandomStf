#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

struct Lnode{
    int val;
    Lnode* sljedeci;
    Lnode* prethodni;
};

struct DLList{
    Lnode* glava;
    Lnode* rep;
};


void pushFront(DLList* t, Lnode* el){
    if(t->glava == t->rep && t->glava == nullptr){
        el->prethodni = nullptr;
        el->sljedeci = nullptr;
        t->glava = el;
        t->rep = el;
    }
    else{
        Lnode* tmp = t->glava;      //zapamti stari
        el->prethodni = nullptr;    //novi nema prethodnog
        tmp->prethodni = el;        //stari je dobio novog kao prethodnog
        el->sljedeci = tmp;         //sljedeci od novog je stari
        t->glava = el;              //glava sad pokazuje na novi el.
    }
}

// void pushBack(DLList* rp, DLList* el){

// }

void printDLList(DLList* t){
    Lnode* tmp = t->glava;
    while(tmp != nullptr){
        cout<<endl<<tmp->val;
        tmp = tmp->sljedeci;
    }
    cout<<endl;
}


int main(){

    srand (time(NULL));

    DLList* popis = new DLList{nullptr,nullptr};
    Lnode* tmp = new Lnode;


    for(int i = 0; i<10; i++){
        tmp = new Lnode;
        tmp->val = rand() % 10 + 1;
        pushFront(popis,tmp);
    }


    printDLList(popis);




    cout<<endl;
    return 0;
}