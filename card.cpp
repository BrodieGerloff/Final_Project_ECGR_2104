#include "card.h"

using namespace std;

Card::Card(std::string n; int cost; int a, int d) {
    name = n;
    
    manaCost = cost;
    if (manaCost < 0) {
        manaCost = 0;
    }
    
    attack = a;
    if (attack < 0) {
        attack = 0;
    }
    
    defense = d;
    if (defense < 0) {
        defense = 0;
    }
}

string Card::render(int line){
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: return "|           |";
        case 3: return "|           |";
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}