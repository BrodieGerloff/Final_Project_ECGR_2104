#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
#include "goblin.h"
#include "card.h"
#include "iron_golem.h"
#include "blademaster.h"
#include "elite.h"
#include "hammer.h"
#include "handgun.h"
#include "loremaster.h"
#include "militia.h"
#include "pharaoh.h"
#include "spear.h"
#include "sword.h"
#include "wizard.h"

using namespace std;

void getOpponentAction(Board&, Board&);
void renderBoard(Board&, Board&);
void getPlayerAction(Board&, Board&);

int main(int argc, char * argv[]){
    srand(time(0));
    int turn = 1;
    
    int playerFirst = rand() % 2;
    
    // Set up Player board
    Board pb;
    for (int i = 0; i < 2; i++) {
        pb.addToDeckList(new Blademaster);
        pb.addToDeckList(new Elite);
        pb.addToDeckList(new Hammer);
        pb.addToDeckList(new Handgun);
        pb.addToDeckList(new Loremaster);
        pb.addToDeckList(new Militia);
        pb.addToDeckList(new Pharaoh);
        pb.addToDeckList(new Spear);
        pb.addToDeckList(new Sword);
        pb.addToDeckList(new Wizard);
    }
    
    pb.shuffleDeck();
    pb.draw(5);
    
    // Set up opponent board
    Board ob;
    for (int i = 0; i < 2; i++) {
        ob.addToDeckList(new Blademaster);
        ob.addToDeckList(new Elite);
        ob.addToDeckList(new Hammer);
        ob.addToDeckList(new Handgun);
        ob.addToDeckList(new Loremaster);
        ob.addToDeckList(new Militia);
        ob.addToDeckList(new Pharaoh);
        ob.addToDeckList(new Spear);
        ob.addToDeckList(new Sword);
        ob.addToDeckList(new Wizard);
    }
    
    ob.shuffleDeck();
    ob.draw(5);
    
    while(pb.getHP() > 0 && ob.getHP() > 0){
        pb.setMana(turn);
        ob.setMana(turn);
        if (playerFirst = 0);
        

        turn++;
    } 
    
    return 0;
}

void renderBoard(Board & pb, Board & ob){
    // Render opponent field
    ob.renderField();
    cout << endl;
    // Render player field
    pb.renderField();
    pb.renderHand();
    
    pb.renderMana();
    cout << "HP: " << pb.getHP() << " Opponent's HP: " << ob.getHP() << endl;
    
    //clearScreen(1);
}

void getOpponentAction(Board & playerBoard, Board & opponentBoard){
    // Go through hand and play cards that the opponent can afford to play
    for(int i = 0; i < opponentBoard.getHandSize(); i++){
        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){
            opponentBoard.playCardFromHand(i);
        }
        renderBoard(playerBoard, opponentBoard);
    }
   
    // Attack with all creatures not exhausted
    for(int i = 0; i < opponentBoard.getFieldSize(); i++){
        if(!opponentBoard.getCardOnField(i)->isExhausted()){
            // get target for attack
            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target
            int targetIndex = -1;
            for(int j = 0; j < playerBoard.getFieldSize(); j++){
                if(opponentBoard.getCardOnField(i)->getAttack() > opponentBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destory creature
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " destoryed your " << playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
                playerBoard.discardCardFromField(targetIndex);
                renderBoard(playerBoard, opponentBoard);
            } else {
                // opponent's creature attacks player directly
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " attacks you directly for " << opponentBoard.getCardOnField(i)->getAttack() << " damage!" << endl;
                playerBoard.setHP(playerBoard.getHP() - opponentBoard.getCardOnField(i)->getAttack());
            }
        }
                
    }
}

void getPlayerAction(Board & pb, Board & ob) {
    
}