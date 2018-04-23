#ifndef BLADEMASTER_H
#define BLADEMASTER_H

#include <iostream>
#include "card.h"

using namespace std;

class Blademaster : public Card {
    private:
    
    public:
    
    Blademaster(void);
    virtual string render(int);
};

#endif
