#ifndef Elite_H
#define Elite_H

#include <iostream>
#include "card.h"

using namespace std;

class Elite : public Card {
    private:
    
    public:
    
    Elite(void);
    virtual string render(int);
};

#endif
