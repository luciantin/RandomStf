#ifndef BIRD_CLASS_H
#define BIRD_CLASS_H

#include "Animal.h"
#include <string>

class Bird : public Animal{
    private:
    const bool canFly;
    
    protected:
    Bird(std::string Cname,std::string Lname,double wgh,bool Hpet,bool canFLY):
        canFly(canFLY),
        Animal(Cname,Lname,wgh,Hpet){};

    public:
    Bird() = delete;
    bool CanFly(){return canFly;};

};

class Penguin : public Bird{
    public:
    Penguin(double wgh,bool Hpet):Bird("Penguin","LatinPenguin",wgh,Hpet,false){};
};

class Crow : public Bird{
    public:
    Crow(double wgh,bool Hpet):Bird("Crow","LatinCrow",wgh,Hpet,true){};
};

#endif