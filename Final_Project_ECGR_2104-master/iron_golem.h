#ifndef IRON_GOLEM_H
#define IRON_GOLEM_H

#include <iostream>
#include "card.h"

using namespace std;

class Iron_Golem : public Card {
    private:
    
    public:
    
    Iron_Golem(void);
    virtual string render(int);
};

#endif