#ifndef MILITIA_H
#define MILITIA_H

#include <iostream>
#include "card.h"

using namespace std;

class Militia : public Card {
    private:
    
    public:
    
    Militia(void);
    virtual string render(int);
};



#endif