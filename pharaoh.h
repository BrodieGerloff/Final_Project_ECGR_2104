#ifndef PHARAOH_H
#define PHARAOH_H

#include <iostream>
#include "card.h"

using namespace std;

class Pharaoh : public Card {
    private:
    
    public:
    
    Pharaoh(void);
    virtual string render(int);
};

#endif
