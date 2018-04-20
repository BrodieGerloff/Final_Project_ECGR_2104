#include "loremaster.h"


loremaster :: card(){
	manaCost = 4;
	attack = 500;
	defense = 400
}

string loremaster::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|Loremaster |";
        case 2: return "|     |+|   |";
        case 3: return "|     |+|   |";
        case 4: return "|     |+|   |";
        case 5: return "|     |+|   |";
        case 6: return "|  500/400  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
