#include <iostream>


using namespace std;



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
        cout<<endl<<"0 - New Node"<<endl<<"1 - List Nodes"<<endl<<"5 - Exit"<<endl;
        int tmp;
        cin>>tmp; 
        if(tmp == 0) {
            cin>>tmp;
            nova(zadnja(sveDretve), tmp);
        }
        if(tmp == 1) ispisId(sveDretve);
        if(tmp == 5) break;
    }



    return 0;
}