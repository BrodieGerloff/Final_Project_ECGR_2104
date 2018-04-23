#include "card.h"

using namespace std;

Card::Card(string n, int cost, int a, int d) {
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
    
    exhausted = true;
}

string Card::getName(void) {
    return name;
}

int Card::getManaCost(void) {
    return manaCost;
}

int Card::getAttack(void) {
    return attack;
}

int Card::getDefense(void) {
    return defense;
}

bool Card::isExhausted(void) {
    return exhausted;
}

void Card::unExhaust(void) {
    exhausted = false;
}

void Card::exhaustCard(void) {
    exhausted = true;
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