#ifndef SPEAR_H
#define SPEAR_H

#include <iostream>
#include "card.h"

using namespace std;

class Spear : public Card {
    private:
    
    public:
    
    Spear(void);
    virtual string render(int);
};


#endif
