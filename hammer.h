#ifndef HAMMER_H
#define HAMMER_H

#include <iostream>
#include "card.h"

using namespace std;

class Hammer : public Card {
    private:
    
    public:
    
    Hammer(void);
    virtual string render(int);
};

#endif
