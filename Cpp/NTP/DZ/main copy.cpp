#include <iostream>


using namespace std;


struct tstudent{
    int mat_br;
    char prez_ime[35];
    int god_stu;
    tstudent* sljedeci;
};


void push_front(tstudent* t,tstudent* novi){ 
    tstudent* tmp = t->sljedeci;
    t->sljedeci = novi;
    novi->sljedeci = tmp;
}

void front(tstudent* glava){
    if(glava->sljedeci != nullptr) cout<<glava->sljedeci->mat_br<<endl;
    else cout<<endl<<"Prazna Lista"<<endl;
}

void ispisSvi(tstudent* t){
    cout<<endl<<"Svi"<<endl;
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

void pop_front(tstudent* glava){
    tstudent* tmp = glava->sljedeci->sljedeci;
    delete glava->sljedeci;
    glava->sljedeci = tmp;
}

void pop_back(tstudent* t){
    while(t->sljedeci->sljedeci != nullptr){
        t = t->sljedeci;
    }   

    delete t->sljedeci;
    t->sljedeci = nullptr;
}


void reverse(tstudent* glava){
    tstudent *rev, *t;    
    
    rev->sljedeci;

    t = glava->sljedeci;

    while(t != nullptr){

        tstudent* pmt;        
        tstudent* tmp = t;
        t = t->sljedeci;

        tmp->sljedeci = nullptr;
        pmt = rev->sljedeci;
        // rev-sljdede

        // rev->sljedeci = tmp;
    }

    // glava->sljedeci = rev;
}




int main(){

    tstudent* popis = new tstudent;
    tstudent* tmp = new tstudent;
    tstudent* &prvi = popis->sljedeci;

    popis->sljedeci = nullptr;

    tmp = new tstudent;
    tmp->mat_br = 1;
    push_front(popis,tmp);
    
    tmp = new tstudent;
    tmp->mat_br = 2;
    push_front(popis,tmp);
    
    tmp = new tstudent;
    tmp->mat_br = 3;
    push_front(popis,tmp);
    
    

    reverse(popis);

    cout<<endl<<"Svi elementi : "<<endl;
    ispisSvi(prvi);

    cout<<endl<<"Prvi element : ";
    front(popis);

    cout<<endl<<"Zadnji element : ";
    back(popis);



    pop_front(popis);
    pop_back(popis);

    cout<<endl<<"Svi elementi nakon brisanja prvog i zadnjeg: "<<endl;
    ispisSvi(prvi);

    return 0;

}