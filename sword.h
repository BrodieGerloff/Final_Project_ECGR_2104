#ifndef SWORD_H
#define SWORD_H

#include <iostream>
#include "card.h"

using namespace std;

class Sword : public Card {
    private:
    
    public:
    
    Sword(void);
    virtual string render(int);
};


#endif
