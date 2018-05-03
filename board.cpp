#include "board.h"

using namespace std;

Board::Board(void) {
    hp = 2000;
}

void Board::addToDeckList(Card* a){
    deck.push_back(a);
}

void Board::draw(int a) {
    for (int i = 0; i < a; i++) {
        if (deck.size() == 0) {
            deck = discard;
            discard.clear();
            shuffleDeck();
        }
        hand.push_back(deck[deck.size() - 1]);
        deck.pop_back();
    }
}

void Board::playCardFromHand(int i) {
    if (getHandSize() >= 7) {
        cout << "You can only have 7 cards on the field." << endl;
    }
    else {
        if (mana >= hand[i]->getManaCost()) {
            mana = mana - hand[i]->getManaCost();
            field.push_back(hand[i]);
            hand.erase(hand.begin() + i);
        }
        else {
            cout << "Not enough mana." << endl;
        }
    }
    
}

Card* Board::getCardOnField(int i) {
    return field[i];
}

Card* Board::getCardInHand(int i) {
    return hand[i];
}

int Board::getHP(void) {
    return hp;
}

void Board::setHP(int i) {
    hp = i;
    if (i < 0) {
        hp = 0;
    }
}

int Board::getHandSize(void) {
    return hand.size();
}

int Board::getFieldSize(void) {
    return field.size();
}

int Board::getMana(void) {
    return mana;
}

void Board::setMana(int i) {
    mana = i;
    if (mana < 0) {
        mana = 0;
    }
    if (mana > 10) {
        mana = 10;
    }
    maxMana = mana;
}

void Board::discardCardFromField(int i) {
    discard.push_back(field[i]);
    field.erase(field.begin() + i);
}

void Board::unExhaustField(void) {
    for (int i = 0; i < field.size(); i++) {
        field[i]->unExhaust();
    }
}

void Board::shuffleDeck(void){
    Card * temp;
    int numOfShuffles = 100;
    int idx1, idx2;
    for(int i = 0; i < numOfShuffles; i++){
        idx1 = rand() % deck.size();
        idx2 = rand() % deck.size();
        temp = deck[idx1];
        deck[idx1] = deck[idx2];
        deck[idx2] = temp;
    }
}


void Board::renderMana(void){
    cout << "MANA: ";
    for(int i = 1; i <= maxMana; i++){
        if(i <= mana)
            cout << "@ ";
        else
            cout << "O ";
    }
        
    cout << endl;
}

void Board::renderHand(void){
    if(hand.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < hand.size(); j++){
                cout << hand[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}

void Board::renderField(void){
    if(field.size() > 0){
        for(int i = 0; i <= 7; i++){
            for(int j = 0; j < field.size(); j++){
                cout << field[j]->render(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i <= 7; i++)
            cout << endl;
    }
}