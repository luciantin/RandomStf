#ifndef MAMMAL_CLASS_H
#define MAMMAL_CLASS_H

#include "Animal.h"
#include <string>

class Mammal : public Animal{
    private:
    const bool isCarnivore,isHerbivore,isOmnivore;

    protected:
    Mammal(std::string Cname,std::string Lname,double wgh,bool Hpet,bool carnivore,bool herbivore, bool omnivore):
        isCarnivore(carnivore),isHerbivore(herbivore),isOmnivore(omnivore),
        Animal(Cname,Lname,wgh,Hpet){};

    public:
    Mammal() = delete;
    bool IsCarnivore(){return isCarnivore;};
    bool IsHerbivore(){return isHerbivore;};
    bool IsOmnivore(){return isOmnivore;};
};

class Tiger : public Mammal{
    public:
    Tiger(double wgh,bool Hpet):
        Mammal("Tiger","LatinTiger",wgh,Hpet,true,false,false){};

    const char* GetType() {return typeid(Mammal).name();};    
};

class Raccoon : public Mammal{
    public:
    Raccoon(double wgh,bool Hpet):
        Mammal("Raccoon","LatinRaccoon",wgh,Hpet,false,false,true){};
};

#endif