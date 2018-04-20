#include "Militia.h"

militia :: card(){
	manaCost = 1;
	attack = 100;
	defense = 300
}

string Militia::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Militia    |";
        case 2: return "|  /-----\  |";
        case 3: return "|  |	 |  |";
        case 4: return "|  |     |  |";
        case 5: return "|  \ ___ /  |";
        case 6: return "|  100/300  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}