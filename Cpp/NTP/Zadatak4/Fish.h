#ifndef FISH_CLASS_H
#define FISH_CLASS_H

#include "Animal.h"
#include <string>

class Fish : public Animal{
    protected:
    Fish(std::string Cname,std::string Lname,double wgh,bool Hpet):Animal(Cname,Lname,wgh,Hpet){};
    public:
    Fish() = delete;
};

class Shark : public Fish{
    private:
    static const bool isDangerous = true;

    public:
    Shark(double wgh,bool Hpet):
        Fish("Shark","LatinShark",wgh,Hpet){};
        
    Shark() = delete;

    bool IsDangerous();
};

class WhiteCatFish : public Fish{
    private:
    bool isCat,isFish;

    public:
    WhiteCatFish(double wgh,bool Hpet,bool isCAT,bool isFISH):
        isCat(isCAT),isFish(isFISH),Fish("WhiteCatFish","LatinWhiteCatFish",wgh,Hpet){};
    
    bool IsCatFish();
    bool IsCat();
    bool IsFish();

};

#endif