#include <iostream>
#include <string>
#include <vector>

#include "Animal.h"
#include "Fish.h"
#include "Mammal.h"
#include "Bird.h"

#define newline std::cout<<std::endl;
#define text(x) std::cout<<x;
#define textln(x) std::cout<<x<<std::endl;


int main(){

    int input;
    int kol[7] = {0,0,0,0,0,0,0};
    std::vector< std::pair<void*,int> > Zivotinje;

    text("Stvaranje Zivotinja");
    newline;


    while(true){
        double tezina;
        int kucnaZiv;
        void* zivotinja;
        
        textln("Koju zivotinju zelite dodat : ");
        textln("1 - Tiger ; 2 - Raccoon ; 3 - Penguin ");
        textln("4 - Crow ; 5 - Shark ; 6 - WhiteCatFish ");
        textln("-1 za izlaz");
        std::cin>>input;
        if(input < 1 || input > 6) break;

        textln("Kucna Zivotinja (1 da/0 ne) :");
        std::cin>>kucnaZiv;
        if(kucnaZiv != 0 && kucnaZiv != 1) continue;

        textln("Tezina zivotinje :");
        std::cin>>tezina;

        if(input==1){      zivotinja = new Tiger(tezina,kucnaZiv);  }
        else if(input==2){ zivotinja = new Raccoon(tezina,kucnaZiv);}
        else if(input==3){ zivotinja = new Penguin(tezina,kucnaZiv);}
        else if(input==4){ zivotinja = new Crow(tezina,kucnaZiv);}
        else if(input==5){ zivotinja = new Shark(tezina,kucnaZiv);}
        else if(input==6){ 
            bool macka,riba;
            textln("Je li to riba (0/1)?");
            std::cin>>riba;
            textln("Je li to macka (0/1)?");
            std::cin>>macka;
            zivotinja = new WhiteCatFish(tezina,kucnaZiv,macka,riba);}

        Zivotinje.push_back(std::pair<void*,int>(zivotinja,input));

        newline; newline; newline;
    }

    newline; newline; newline;

    text("Unesene Zivotinje : ");

    newline; newline; newline;

    for(std::vector< std::pair<void*,int> >::iterator it = Zivotinje.begin();it<Zivotinje.end();it++){
        newline;

        kol[it->second]++;

        text("Ime : "); std::cout<<((Animal*)it->first)->GetCommonName(); newline;
        text("Ime na latinski : "); std::cout<<((Animal*)it->first)->GetLatinName(); newline;
        text("Tezina :"); std::cout<<((Animal*)it->first)->GetWheight(); newline;
        text("Kucna zivotinja ? : "); std::cout<<(((Animal*)it->first)->IsHousePet() ? "Da" : "Ne" ); newline;

        if(it->second == 1){ 
            text("Vrsta : ");
            text(((Tiger*)it->first)->GetType()); newline;
            textln("Sta jede ? ");
            text("Trava ? ");   std::cout<<(((Tiger*)it->first)->IsHerbivore() ? "Da" : "Ne" ); newline;
            text("Meso ? ");    std::cout<<(((Tiger*)it->first)->IsCarnivore() ? "Da" : "Ne" ); newline;
            text("Sve ? ");     std::cout<<(((Tiger*)it->first)->IsOmnivore() ? "Da" : "Ne" ); newline;

            delete (Tiger*)it->first;
        }
        if(it->second == 2){ 
            textln("Sta jede ? ");
            text("Trava ? ");   std::cout<<(((Raccoon*)it->first)->IsHerbivore() ? "Da" : "Ne" ); newline;
            text("Meso ? ");    std::cout<<(((Raccoon*)it->first)->IsCarnivore() ? "Da" : "Ne" ); newline;
            text("Sve ? ");     std::cout<<(((Raccoon*)it->first)->IsOmnivore() ? "Da" : "Ne" ); newline;

            delete (Raccoon*)it->first; 
        }
        if(it->second == 3){ 
            text("Leti ? ")     std::cout<<(((Penguin*)it->first)->CanFly() ? "Da" : "Ne" ); newline;
            delete (Penguin*)it->first; 
        }
        if(it->second == 4){ 
            text("Leti ? ")     std::cout<<(((Crow*)it->first)->CanFly() ? "Da" : "Ne" ); newline;
            delete (Crow*)it->first; 
        }
        if(it->second == 5){
            text("Opasan ? ");  std::cout<<(((Shark*)it->first)->IsDangerous() ? "Da" : "Ne" ); newline;
            delete (Shark*)it->first;
        }
        if(it->second == 6){
            text("Je li maca ? ");  std::cout<<(((WhiteCatFish*)it->first)->IsCat() ? "Da" : "Ne" ); newline;
            text("Je li riba ? ");  std::cout<<(((WhiteCatFish*)it->first)->IsFish() ? "Da" : "Ne" ); newline;
            text("Je li maca-riba ? "); std::cout<<(((WhiteCatFish*)it->first)->IsCatFish() ? "Da" : "Ne" ); newline;
            delete (WhiteCatFish*)it->first;
        }

    }
    
    newline; newline; newline;

    text("Ukupno Zivotinja : ");

    newline; newline; newline;

    text("Tiger : ");          textln(kol[1]);
    text("Raccoon : ");        textln(kol[2]);
    text("Penguin : ");        textln(kol[3]);
    text("Crow : ");           textln(kol[4]);
    text("Shark : ");          textln(kol[5]);
    text("WhiteCatFish : ");   textln(kol[6]);

    return 0;
}

/*
textln("1 - Tiger ; 2 - Raccoon ; 3 - Penguin ");
        textln("4 - Crow ; 5 - Shark ; 6 - WhiteCatFish ");
*/