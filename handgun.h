#ifndef HANDGUN_H
#define HANDGUN_H

#include <iostream>
#include "card.h"

using namespace std;

class Handgun : public Card {
    private:
    
    public:
    
    Handgun(void);
    virtual string render(int);
};

#endif