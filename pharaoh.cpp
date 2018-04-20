#include "Pharaoh.h"


pharoah :: card(){
	manaCost = 6;
	attack = 500;
	defense = 500
}

string Pharaoh::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|PHARAOH    |";
        case 2: return "|     [+]   |";
        case 3: return "|      o    |";
        case 4: return "|      o    |";
        case 5: return "|      o    |";
        case 6: return "|  500/500  |";
        case 7: return "|___________|";
        default:
            return " ";
    }