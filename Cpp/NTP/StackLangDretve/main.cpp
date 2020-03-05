#include <iostream>
// #include <stdlib.h>
// #include <vector>

// #define MAX_MEM 1000

using namespace std;

// char* MEMORY = (char*)malloc(MAX_MEM*sizeof(char));
// char* PROGRAM = (char*)malloc(MAX_MEM*sizeof(char));



// void printMemory(int start,int size){    
//     for(int max = start + size; start != max; start++)  cout<<endl<<*(MEMORY + start)<<endl;
// }

struct dretva{
    int id;
    dretva* prev;
    dretva* next;
};


dretva* sljedeca(dretva* t){ return t->next;}

dretva* nova(dretva* t,int id){ 
    t->next = new dretva;
    t->next->prev = t;
    t->next->next = nullptr;
    t->next->id = id;
    return t->next;
}

dretva* zadnja(dretva* t){ while(t->next != nullptr) t = t->next; return t;   }

void ispisId(dretva* t){
    cout<<endl;
    while(t != nullptr){
        cout<<t->id<<endl;
        t = t->next;
    }    
}



int main(){

    dretva* sveDretve = new dretva;


    sveDretve->id = 999;
    sveDretve->next = nullptr;
    sveDretve->prev = nullptr;
    
    
    while(true){
        cout<<endl<<"0 - New Node"<<endl<<"1 - List Nodes"<<endl;
        int tmp;
        cin>>tmp;
        if(tmp == 0) {
            cin>>tmp;
            nova(zadnja(sveDretve), tmp);
        }
        if(tmp == 1) ispisId(sveDretve);
    }



    return 0;
}