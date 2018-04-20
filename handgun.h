#ifndef HANDGUN_H
#define HANDGUN_H

#include <iostream>
#include "card.h"

using namespace std;

class Handgun : public Card {
    private:
    
    public:
    
    handgun(void);
    virtual string render(int);
};

#endif