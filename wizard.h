#ifndef Wizard_H
#define Wizard_H

#include <iostream>
#include "card.h"

using namespace std;

class Wizard : public Card {
    private:
    
    public:
    
    Wizard(void);
    virtual string render(int);
};

#endif

