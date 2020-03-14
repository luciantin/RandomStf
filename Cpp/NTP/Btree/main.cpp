#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;


struct element{
    int val;
    element* desno;
    element* lijevo;
};

//** lijevo manje ili jednako || desno vece **//
void push(element* &stablo, element* el){
    if(stablo == nullptr) stablo = el;
    else if(stablo->val > el->val){
        if(stablo->lijevo != nullptr) push(stablo->lijevo, el);
        else stablo->lijevo = el;
    }
    else if(stablo->val <= el->val){
        if(stablo->desno != nullptr) push(stablo->desno, el);
        else stablo->desno = el;
    }
    return;
}

void InorderPrint(element* stablo){
    if(stablo == nullptr) return;
    InorderPrint(stablo->lijevo);   //lijevo
    cout<<" "<<stablo->val<<" ,";   //cvor
    InorderPrint(stablo->desno);    //desno
}

//    mapStablo(stablo,[](int a){return a+1;});
void mapStablo(element* stablo,int f(int)){
    if(stablo == nullptr) return;
    mapStablo(stablo->lijevo,f);   
    mapStablo(stablo->desno,f);    
    stablo->val = f(stablo->val);
}


int main(){


    srand (time(NULL));

    element* stablo = nullptr, *tmp;

    int len = 10;
    int polje[10] = {1,2,3,4,5,5,1,9,3,4};

    for(int i = 0; i < 10; i++) push(stablo, new element{polje[i], nullptr,nullptr});

    InorderPrint(stablo);
    cout<<endl;


    // map(stablo,[](int a){ return 1;});
    mapStablo(stablo,[](int a){return a+1;});
    mapStablo(stablo,[](int a){return a+1;});
    mapStablo(stablo,[](int a){return a+1;});

  
    cout<<endl;

    InorderPrint(stablo);
    cout<<endl;

    return 0;
}