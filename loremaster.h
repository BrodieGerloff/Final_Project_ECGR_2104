#ifndef LORE_H
#define LORE_H

#include <iostream>
#include "card.h"

using namespace std;

class Loremaster : public Card {
    private:
    
    public:
    
    Loremaster(void);
    virtual string render(int);
};

#endif
