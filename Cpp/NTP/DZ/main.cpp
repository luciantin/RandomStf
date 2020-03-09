#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;


struct tstudent{
    int mat_br;
    char prez_ime[35];
    int god_stu;
    tstudent* sljedeci;
};


void push_front(tstudent* &glava,tstudent* &novi){ 
    novi->sljedeci = glava;
    glava = novi;
}

void front(tstudent* glava){
    if(glava != nullptr) cout<<glava->mat_br<<endl;
    else cout<<endl<<"Prazna Lista"<<endl;
}

void ispisSvi(tstudent* t){
    while(t != nullptr){
        cout<<t->mat_br<<endl;
        t = t->sljedeci;
    }    
}

void back(tstudent* t){
    while(t->sljedeci != nullptr){
        t = t->sljedeci;
    }    
    cout<<t->mat_br<<endl;
}

void pop_front(tstudent* &glava){
    if(glava == nullptr) return;

    tstudent* tmp = glava->sljedeci;
    delete glava;
    glava = tmp;
}

void pop_back(tstudent* t){

    if(t == nullptr) return;
    else if(t->sljedeci == nullptr){
        delete t;
        return;
    }

    while(t->sljedeci->sljedeci != nullptr)t = t->sljedeci;

    delete t->sljedeci;
    t->sljedeci = nullptr;
}


void reverse(tstudent* &glava){
    tstudent *rev, *t;    

    rev = nullptr;
    t = glava;

    while(t != nullptr){
        tstudent* tmp = t->sljedeci;
        push_front(rev,t);
        t = tmp;
    }

    glava = rev;
}


void sort(tstudent* &glava){
    tstudent *t = glava, *prev = glava, *nxt;
    bool flg = true;

    if(t->sljedeci == nullptr) return;

    if(t->sljedeci->sljedeci == nullptr){
        if(t->sljedeci->mat_br > prev->mat_br){
            push_front(glava,t->sljedeci);
            glava->sljedeci->sljedeci = nullptr;
            return;
        }
        else return;
    }


    while(flg){

        prev = glava;
        t = glava->sljedeci;
        nxt = t->sljedeci;

        flg = false;

        if(prev->mat_br < t->mat_br){
            glava = t;
            glava->sljedeci = prev;
            glava->sljedeci->sljedeci = nxt;   
            prev = glava;
            t = glava->sljedeci;
            nxt = t->sljedeci;      
        }
        
        while(nxt != nullptr){
            if(t->mat_br < nxt->mat_br){
                tstudent *tmp = nxt->sljedeci;
                prev->sljedeci = nxt;
                nxt->sljedeci = t;
                t->sljedeci = tmp;
                flg=true;
            }
         
            prev = t;
            t = nxt;
            nxt = nxt->sljedeci;
        }
    }
}


int main(){

    tstudent* popis = nullptr;
    // tstudent* tmpA,*tmpB,*tmpC;
    tstudent* tmp_st;

    srand (time(NULL));
    
    for(int i = 0; i<10; i++){
        tmp_st = new tstudent;
        tmp_st->mat_br = rand() % 10 + 1;
        push_front(popis,tmp_st);
    }

    cout<<endl<<"Svi elementi : "<<endl;
    ispisSvi(popis);

    cout<<"-----------------";

    cout<<endl<<"front : ";
    front(popis);
    cout<<endl<<"back : ";
    back(popis);

    cout<<"-----------------";

    pop_back(popis);
    pop_front(popis);

    cout<<endl<<"Elementi nakon popanja : "<<endl;
    ispisSvi(popis);

    cout<<"-----------------";

    cout<<endl<<"Reverse elementi : "<<endl;
    reverse(popis);
    ispisSvi(popis);

    cout<<"-----------------"<<endl;

    // popis->sljedeci->sljedeci->sljedeci->mat_br = 35;

    cout<<"Sortirani"<<endl;

    sort(popis);
    ispisSvi(popis);


    return 0;

}