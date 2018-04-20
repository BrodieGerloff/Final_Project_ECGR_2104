#include "iron_golem.h"

Iron_Golem::Iron_Goblin(void) : Card::Card("Iron Golem", 3, 400, 400) {}

string Iron_Golem::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Iron Golem |";
        case 2: return "|   __||__  |";
        case 3: return "|  |  ||  | |";
        case 4: return "|  |  ||  | |";
        case 5: return "|   \\_||_/  |";
        case 6: return "|  400/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
