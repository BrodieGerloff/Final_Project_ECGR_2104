#include "Sword.h"

sword :: card(){
	manaCost = 2;
	attack = 300;
	defense = 200
}

string Sword::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Sword      |";
        case 2: return "|     /\    |";
        case 3: return "|     ||    |";
        case 4: return "|     ||    |";
        case 5: return "|     ||    |";
        case 6: return "|  300/200  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}