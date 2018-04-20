#include "Wizard.h"

Wizard::Wizard(void) : Card::Card("Wizard", 3, 400, 400) {}

string Wizard::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|Wizard     |";
        case 2: return "|     |     |";
        case 3: return "|    +|+    |";
        case 4: return "|    +|+    |";
        case 5: return "|     |     |";
        case 6: return "|  400/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}