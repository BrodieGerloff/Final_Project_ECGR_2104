#include "elite.h"

elite::elite(void) : Card::Card("Elite", 4, 300, 500) {}

string Elite::render(int line){
    
 switch(line){
        case 0: return ".___________.";
        case 1: return "|Elite      |";
        case 2: return "|  /-----\  |";
        case 3: return "|  |+	+|  |";
        case 4: return "|  |+   +|  |";
        case 5: return "|  \ ___ /  |";
        case 6: return "|  300/500  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
