#ifndef ANIMAL_CLASS_H
#define ANIMAL_CLASS_H

#include <string>

class Animal{
    private:
    const double WHEIGHT;
    const std::string LATIN_NAME;
    const std::string COMMON_NAME;
    const bool isHousePet;
    
    protected:
    Animal(std::string Cname,std::string Lname,double wgh,bool Hpet):
        WHEIGHT{wgh},LATIN_NAME{Lname},COMMON_NAME{Cname},isHousePet{Hpet}{};

    public:
    Animal() = delete;
    bool IsHousePet();
    std::string GetLatinName();
    std::string GetCommonName();
    double GetWheight();
};



#endif