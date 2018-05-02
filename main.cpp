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
    
    //while(pb.getHP() > 0 && ob.getHP() > 0){
        pb.setMana(turn);
        ob.setMana(turn);
        renderBoard(pb,ob);
        pb.draw(5 - pb.getHandSize());
        ob.draw(5 - ob.getHandSize());
        getPlayerAction(pb,ob);

        turn++;
        //std::system("clear");
    //} 
    
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
        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana() && opponentBoard.getFieldSize() < 7){                   //Changed opponent to limit to at most 7 cards on the field
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
                if(opponentBoard.getCardOnField(i)->getAttack() >= playerBoard.getCardOnField(j)->getDefense()){
                    targetIndex = j;
                    break;
                }
            }
            if(targetIndex != -1){
                // destory creature
                cout << "Opponent's " << opponentBoard.getCardOnField(i)->getName() << " destroyed your " << playerBoard.getCardOnField(targetIndex)->getName() << "!" << endl;
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
    int play = 1;
    int attack = 1;
    int target = 1;
    while(true) {
        cout << "Pick which card to play or press 9 to move to attack phase-" << endl;
        
        for (int i = 0; i < pb.getHandSize(); i++) {
            cout << i << ": " << pb.getCardInHand(i)->getName() << " Cost: " << pb.getCardInHand(i)->getManaCost() << endl;
        }
        cout << "9: Move to attack phase" << endl;
        
        cin >> play;
        
        if(play != 9) {
            if (play >= 0 && play < pb.getHandSize()) {
                pb.playCardFromHand(play);
                renderBoard(pb, ob);
            }
            else {
                cout << "Invalid input." << endl;
            }  
        }
        else {
            break;
        }
    }
    
    //Player attacks with available cards
    while(ob.getHP() > 0) {
        cout << "Pick which card to attack with, or press 9 to end turn-" << endl;
        
        for (int i = 0; i < pb.getFieldSize(); i++) {
            cout << i << ": " << pb.getCardInHand(i)->getName() << " Exhausted: ";
            if (pb.getCardOnField(i)->isExhausted()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        cout << "9: End turn" << endl;
        
        cin >> attack;
        
        if (attack == 9) {
            break;
        }
        else if (attack >= 0 && attack < pb.getFieldSize()) {                                                                                                       //Valid card check
            if (!pb.getCardOnField(attack)->isExhausted()) {                                                                                                        //Exhaustion check
                cout << "Pick which card to attack, or press 9 to attack opponent directly-" << endl;
                cin >> target;
                
                if(target = 9){
                    // player's creature attacks opponent directly
                    cout << "Your " << pb.getCardOnField(attack)->getName() << " attacks your foe directly for " << pb.getCardOnField(target)->getAttack() << " damage!" << endl;
                    ob.setHP(ob.getHP() - pb.getCardOnField(attack)->getAttack());
                    
                } 
                else if (target >= 0 && target < ob.getFieldSize()) {                                                                                               //Second card check
                    if (pb.getCardOnField(attack)->getAttack() >= ob.getCardOnField(target)->getDefense()) {                                                        //Attack check
                        cout << "Your " << pb.getCardOnField(attack)->getName() << " destroyed their " << ob.getCardOnField(target)->getName() << "!" << endl;
                        ob.discardCardFromField(target);
                        pb.getCardOnField(attack)->exhaustCard();
                        renderBoard(pb, ob);
                    }
                    else {
                        cout << "Your card is not strong enough to destroy the opponent's card." << endl;
                    }
                }
                else {
                    cout << "Invalid input." << endl;
                }
            }
            else {
                cout << "That card is exhausted for this turn." << endl;
            }
                
        }
        else {
            cout << "Invalid input." << endl;
        }
            
    }
    
}

    /*while(attack > 0) {
        cout << "Pick which card to attack with or press 9 to quit" << endl;
        cin >> attack;
        cout << "Pick which card to attack" << endl;
        cin >> target;
        
        if(target != -1){
            // destory creature
            cout << "Your " << pb.getCardOnField(attack)->getName() << " destroyed their " << ob.getCardOnField(target)->getName() << "!" << endl;
            ob.discardCardFromField(target);
            renderBoard(pb, ob);
        } else {
            // opponent's creature attacks player directly
            cout << "Your " << pb.getCardOnField(attack)->getName() << " attacks your foe directly for " << pb.getCardOnField(target)->getAttack() << " damage!" << endl;
            ob.setHP(ob.getHP() - pb.getCardOnField(attack)->getAttack());
        }
    } */