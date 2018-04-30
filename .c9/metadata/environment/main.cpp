{"filter":false,"title":"main.cpp","tooltip":"/main.cpp","undoManager":{"mark":67,"position":67,"stack":[[{"start":{"row":0,"column":0},"end":{"row":148,"column":1},"action":"insert","lines":["#include <iostream>","#include <stdlib.h>","#include <unistd.h>","#include \"board.h\"","#include \"goblin.h\"","#include \"card.h\"","#include \"iron_golem.h\"","#include \"blademaster.h\"","#include \"elite.h\"","#include \"hammer.h\"","#include \"handgun.h\"","#include \"loremaster.h\"","#include \"militia.h\"","#include \"pharaoh.h\"","#include \"spear.h\"","#include \"sword.h\"","#include \"wizard.h\"","","using namespace std;","","void getOpponentAction(Board&, Board&);","void renderBoard(Board&, Board&);","void getPlayerAction(Board&, Board&);","","int main(int argc, char * argv[]){","    srand(time(0));","    int turn = 1;","    ","    int playerFirst = rand() % 2;","    ","    // Set up Player board","    Board pb;","    for (int i = 0; i < 2; i++) {","        pb.addToDeckList(new Blademaster);","        pb.addToDeckList(new Elite);","        pb.addToDeckList(new Hammer);","        pb.addToDeckList(new Handgun);","        pb.addToDeckList(new Loremaster);","        pb.addToDeckList(new Militia);","        pb.addToDeckList(new Pharaoh);","        pb.addToDeckList(new Spear);","        pb.addToDeckList(new Sword);","        pb.addToDeckList(new Wizard);","    }","    ","    pb.shuffleDeck();","    pb.draw(5);","    ","    // Set up opponent board","    Board ob;","    for (int i = 0; i < 2; i++) {","        ob.addToDeckList(new Blademaster);","        ob.addToDeckList(new Elite);","        ob.addToDeckList(new Hammer);","        ob.addToDeckList(new Handgun);","        ob.addToDeckList(new Loremaster);","        ob.addToDeckList(new Militia);","        ob.addToDeckList(new Pharaoh);","        ob.addToDeckList(new Spear);","        ob.addToDeckList(new Sword);","        ob.addToDeckList(new Wizard);","    }","    ","    ob.shuffleDeck();","    ob.draw(5);","    ","    //while(pb.getHP() > 0 && ob.getHP() > 0){","        pb.setMana(turn);","        ob.setMana(turn);","        renderBoard(pb,ob);","        pb.draw(5 - pb.getHandSize());","        ob.draw(5 - ob.getHandSize());","        ","","        turn++;","        //std::system(\"clear\");","    //} ","    ","    return 0;","}","","void renderBoard(Board & pb, Board & ob){","    // Render opponent field","    ob.renderField();","    cout << endl;","    // Render player field","    pb.renderField();","    pb.renderHand();","    ","    pb.renderMana();","    cout << \"HP: \" << pb.getHP() << \" Opponent's HP: \" << ob.getHP() << endl;","    ","    //clearScreen(1);","}","","void getOpponentAction(Board & playerBoard, Board & opponentBoard){","    // Go through hand and play cards that the opponent can afford to play","    for(int i = 0; i < opponentBoard.getHandSize(); i++){","        if(opponentBoard.getCardInHand(i)->getManaCost() <= opponentBoard.getMana()){","            opponentBoard.playCardFromHand(i);","        }","        renderBoard(playerBoard, opponentBoard);","    }","   ","    // Attack with all creatures not exhausted","    for(int i = 0; i < opponentBoard.getFieldSize(); i++){","        if(!opponentBoard.getCardOnField(i)->isExhausted()){","            // get target for attack","            // look through all cards on player's board. If the card is capable of killing one of those, it will chose the first one as its target","            int targetIndex = -1;","            for(int j = 0; j < playerBoard.getFieldSize(); j++){","                if(opponentBoard.getCardOnField(i)->getAttack() > opponentBoard.getCardOnField(j)->getDefense()){","                    targetIndex = j;","                    break;","                }","            }","            if(targetIndex != -1){","                // destory creature","                cout << \"Opponent's \" << opponentBoard.getCardOnField(i)->getName() << \" destoryed your \" << playerBoard.getCardOnField(targetIndex)->getName() << \"!\" << endl;","                playerBoard.discardCardFromField(targetIndex);","                renderBoard(playerBoard, opponentBoard);","            } else {","                // opponent's creature attacks player directly","                cout << \"Opponent's \" << opponentBoard.getCardOnField(i)->getName() << \" attacks you directly for \" << opponentBoard.getCardOnField(i)->getAttack() << \" damage!\" << endl;","                playerBoard.setHP(playerBoard.getHP() - opponentBoard.getCardOnField(i)->getAttack());","            }","        }","                ","    }","}","","void getPlayerAction(Board & pb, Board & ob) {","    int in = 0;","    while(pb.mana > 0) {","        cout << \"Pick which card to play or press 0 to quit\" << endl;","        cin >> in;","        ","        if(in > 0) {","            board.playCardFromHand(in);    ","        }","        else {","            break;","        }","    }","    ","    //Player attacks with available cards","    ","    //Turn Ends","}"],"id":1}],[{"start":{"row":132,"column":13},"end":{"row":132,"column":14},"action":"remove","lines":["0"],"id":2,"ignore":true},{"start":{"row":132,"column":13},"end":{"row":134,"column":14},"action":"insert","lines":["1;","    int at = 1;","    int de = 1"]},{"start":{"row":148,"column":4},"end":{"row":163,"column":5},"action":"insert","lines":["while(at > 0) {","        cout << \"Pick which card to attack with or press 0 to quit\" << endl;","        cin >> at;","        cout << \"Pick which card to attack\" << endl;","        ","         if(targetIndex != -1){","                // destory creature","                cout << \"Your \" << playerBoard.getCardOnField(at)->getName() << \" destoryed their \" << opponentBoard.getCardOnField(de)->getName() << \"!\" << endl;","                playerBoard.discardCardFromField(targetIndex);","                renderBoard(playerBoard, opponentBoard);","            } else {","                // opponent's creature attacks player directly","                cout << \"Your \" << playerBoard.getCardOnField(at)->getName() << \" attacks your foe directly for \" << opponentBoard.getCardOnField(de)->getAttack() << \" damage!\" << endl;","                opponentBoard.setHP(playerBoard.getHP() - playerBoard.getCardOnField(i)->getAttack());","            }","    }"]}],[{"start":{"row":135,"column":13},"end":{"row":135,"column":14},"action":"insert","lines":["g"],"id":3},{"start":{"row":135,"column":14},"end":{"row":135,"column":15},"action":"insert","lines":["e"]},{"start":{"row":135,"column":15},"end":{"row":135,"column":16},"action":"insert","lines":["t"]}],[{"start":{"row":135,"column":16},"end":{"row":135,"column":17},"action":"remove","lines":["m"],"id":4}],[{"start":{"row":135,"column":16},"end":{"row":135,"column":17},"action":"insert","lines":["M"],"id":5}],[{"start":{"row":135,"column":13},"end":{"row":135,"column":20},"action":"remove","lines":["getMana"],"id":6},{"start":{"row":135,"column":13},"end":{"row":135,"column":20},"action":"insert","lines":["getMana"]}],[{"start":{"row":140,"column":12},"end":{"row":140,"column":17},"action":"remove","lines":["board"],"id":7},{"start":{"row":140,"column":12},"end":{"row":140,"column":13},"action":"insert","lines":["p"]},{"start":{"row":140,"column":13},"end":{"row":140,"column":14},"action":"insert","lines":["b"]}],[{"start":{"row":151,"column":52},"end":{"row":152,"column":0},"action":"insert","lines":["",""],"id":8},{"start":{"row":152,"column":0},"end":{"row":152,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":134,"column":15},"end":{"row":135,"column":0},"action":"insert","lines":["",""],"id":9},{"start":{"row":135,"column":0},"end":{"row":135,"column":4},"action":"insert","lines":["    "]},{"start":{"row":135,"column":4},"end":{"row":135,"column":5},"action":"insert","lines":["i"]},{"start":{"row":135,"column":5},"end":{"row":135,"column":6},"action":"insert","lines":["n"]},{"start":{"row":135,"column":6},"end":{"row":135,"column":7},"action":"insert","lines":["t"]}],[{"start":{"row":135,"column":7},"end":{"row":135,"column":8},"action":"insert","lines":[" "],"id":10},{"start":{"row":135,"column":8},"end":{"row":135,"column":9},"action":"insert","lines":["t"]},{"start":{"row":135,"column":9},"end":{"row":135,"column":10},"action":"insert","lines":["a"]},{"start":{"row":135,"column":10},"end":{"row":135,"column":11},"action":"insert","lines":["r"]},{"start":{"row":135,"column":11},"end":{"row":135,"column":12},"action":"insert","lines":["g"]},{"start":{"row":135,"column":12},"end":{"row":135,"column":13},"action":"insert","lines":["e"]},{"start":{"row":135,"column":13},"end":{"row":135,"column":14},"action":"insert","lines":["t"]}],[{"start":{"row":135,"column":14},"end":{"row":135,"column":15},"action":"insert","lines":[" "],"id":11},{"start":{"row":135,"column":15},"end":{"row":135,"column":16},"action":"insert","lines":["="]}],[{"start":{"row":135,"column":16},"end":{"row":135,"column":17},"action":"insert","lines":[" "],"id":12},{"start":{"row":135,"column":17},"end":{"row":135,"column":18},"action":"insert","lines":["0"]},{"start":{"row":135,"column":18},"end":{"row":135,"column":19},"action":"insert","lines":[";"]}],[{"start":{"row":155,"column":18},"end":{"row":155,"column":23},"action":"remove","lines":["Index"],"id":13}],[{"start":{"row":157,"column":35},"end":{"row":157,"column":46},"action":"remove","lines":["playerBoard"],"id":14},{"start":{"row":157,"column":35},"end":{"row":157,"column":36},"action":"insert","lines":["p"]},{"start":{"row":157,"column":36},"end":{"row":157,"column":37},"action":"insert","lines":["b"]}],[{"start":{"row":157,"column":94},"end":{"row":157,"column":107},"action":"remove","lines":["opponentBoard"],"id":15},{"start":{"row":157,"column":94},"end":{"row":157,"column":95},"action":"insert","lines":["o"]},{"start":{"row":157,"column":95},"end":{"row":157,"column":96},"action":"insert","lines":["b"]}],[{"start":{"row":155,"column":8},"end":{"row":155,"column":9},"action":"remove","lines":[" "],"id":16}],[{"start":{"row":160,"column":8},"end":{"row":160,"column":12},"action":"remove","lines":["    "],"id":17}],[{"start":{"row":164,"column":8},"end":{"row":164,"column":12},"action":"remove","lines":["    "],"id":18}],[{"start":{"row":163,"column":12},"end":{"row":163,"column":16},"action":"remove","lines":["    "],"id":19}],[{"start":{"row":162,"column":12},"end":{"row":162,"column":16},"action":"remove","lines":["    "],"id":20}],[{"start":{"row":161,"column":12},"end":{"row":161,"column":16},"action":"remove","lines":["    "],"id":21}],[{"start":{"row":159,"column":12},"end":{"row":159,"column":16},"action":"remove","lines":["    "],"id":22}],[{"start":{"row":158,"column":12},"end":{"row":158,"column":16},"action":"remove","lines":["    "],"id":23}],[{"start":{"row":157,"column":12},"end":{"row":157,"column":16},"action":"remove","lines":["    "],"id":24}],[{"start":{"row":156,"column":12},"end":{"row":156,"column":16},"action":"remove","lines":["    "],"id":25}],[{"start":{"row":153,"column":8},"end":{"row":153,"column":9},"action":"insert","lines":["c"],"id":26},{"start":{"row":153,"column":9},"end":{"row":153,"column":10},"action":"insert","lines":["i"]},{"start":{"row":153,"column":10},"end":{"row":153,"column":11},"action":"insert","lines":["n"]}],[{"start":{"row":153,"column":11},"end":{"row":153,"column":12},"action":"insert","lines":[" "],"id":27},{"start":{"row":153,"column":12},"end":{"row":153,"column":13},"action":"insert","lines":[">"]},{"start":{"row":153,"column":13},"end":{"row":153,"column":14},"action":"insert","lines":[">"]}],[{"start":{"row":153,"column":14},"end":{"row":153,"column":15},"action":"insert","lines":[" "],"id":28},{"start":{"row":153,"column":15},"end":{"row":153,"column":16},"action":"insert","lines":["t"]},{"start":{"row":153,"column":16},"end":{"row":153,"column":17},"action":"insert","lines":["a"]},{"start":{"row":153,"column":17},"end":{"row":153,"column":18},"action":"insert","lines":["r"]},{"start":{"row":153,"column":18},"end":{"row":153,"column":19},"action":"insert","lines":["g"]},{"start":{"row":153,"column":19},"end":{"row":153,"column":20},"action":"insert","lines":["e"]},{"start":{"row":153,"column":20},"end":{"row":153,"column":21},"action":"insert","lines":["t"]}],[{"start":{"row":153,"column":21},"end":{"row":153,"column":22},"action":"insert","lines":[";"],"id":29}],[{"start":{"row":153,"column":22},"end":{"row":154,"column":0},"action":"insert","lines":["",""],"id":30},{"start":{"row":154,"column":0},"end":{"row":154,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":154,"column":4},"end":{"row":154,"column":8},"action":"remove","lines":["    "],"id":31},{"start":{"row":154,"column":0},"end":{"row":154,"column":4},"action":"remove","lines":["    "]},{"start":{"row":153,"column":22},"end":{"row":154,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":158,"column":12},"end":{"row":158,"column":23},"action":"remove","lines":["playerBoard"],"id":32},{"start":{"row":158,"column":12},"end":{"row":158,"column":13},"action":"insert","lines":["p"]},{"start":{"row":158,"column":13},"end":{"row":158,"column":14},"action":"insert","lines":["b"]}],[{"start":{"row":158,"column":13},"end":{"row":158,"column":14},"action":"remove","lines":["b"],"id":33},{"start":{"row":158,"column":12},"end":{"row":158,"column":13},"action":"remove","lines":["p"]}],[{"start":{"row":158,"column":12},"end":{"row":158,"column":13},"action":"insert","lines":["o"],"id":34},{"start":{"row":158,"column":13},"end":{"row":158,"column":14},"action":"insert","lines":["b"]}],[{"start":{"row":158,"column":42},"end":{"row":158,"column":47},"action":"remove","lines":["Index"],"id":35}],[{"start":{"row":159,"column":24},"end":{"row":159,"column":35},"action":"remove","lines":["playerBoard"],"id":36},{"start":{"row":159,"column":24},"end":{"row":159,"column":25},"action":"insert","lines":["p"]},{"start":{"row":159,"column":25},"end":{"row":159,"column":26},"action":"insert","lines":["b"]}],[{"start":{"row":159,"column":28},"end":{"row":159,"column":41},"action":"remove","lines":["opponentBoard"],"id":37},{"start":{"row":159,"column":28},"end":{"row":159,"column":29},"action":"insert","lines":["o"]},{"start":{"row":159,"column":29},"end":{"row":159,"column":30},"action":"insert","lines":["b"]}],[{"start":{"row":162,"column":31},"end":{"row":162,"column":42},"action":"remove","lines":["playerBoard"],"id":38},{"start":{"row":162,"column":31},"end":{"row":162,"column":32},"action":"insert","lines":["p"]},{"start":{"row":162,"column":32},"end":{"row":162,"column":33},"action":"insert","lines":["b"]}],[{"start":{"row":162,"column":104},"end":{"row":162,"column":117},"action":"remove","lines":["opponentBoard"],"id":39},{"start":{"row":162,"column":104},"end":{"row":162,"column":105},"action":"insert","lines":["p"]},{"start":{"row":162,"column":105},"end":{"row":162,"column":106},"action":"insert","lines":["b"]}],[{"start":{"row":163,"column":12},"end":{"row":163,"column":25},"action":"remove","lines":["opponentBoard"],"id":40},{"start":{"row":163,"column":12},"end":{"row":163,"column":13},"action":"insert","lines":["o"]},{"start":{"row":163,"column":13},"end":{"row":163,"column":14},"action":"insert","lines":["b"]}],[{"start":{"row":163,"column":21},"end":{"row":163,"column":32},"action":"remove","lines":["playerBoard"],"id":41},{"start":{"row":163,"column":21},"end":{"row":163,"column":22},"action":"insert","lines":["o"]},{"start":{"row":163,"column":22},"end":{"row":163,"column":23},"action":"insert","lines":["b"]}],[{"start":{"row":163,"column":34},"end":{"row":163,"column":45},"action":"remove","lines":["playerBoard"],"id":42},{"start":{"row":163,"column":34},"end":{"row":163,"column":35},"action":"insert","lines":["p"]},{"start":{"row":163,"column":35},"end":{"row":163,"column":36},"action":"insert","lines":["b"]}],[{"start":{"row":132,"column":9},"end":{"row":132,"column":10},"action":"remove","lines":["n"],"id":43},{"start":{"row":132,"column":8},"end":{"row":132,"column":9},"action":"remove","lines":["i"]}],[{"start":{"row":132,"column":8},"end":{"row":132,"column":9},"action":"insert","lines":["p"],"id":44},{"start":{"row":132,"column":9},"end":{"row":132,"column":10},"action":"insert","lines":["l"]},{"start":{"row":132,"column":10},"end":{"row":132,"column":11},"action":"insert","lines":["a"]},{"start":{"row":132,"column":11},"end":{"row":132,"column":12},"action":"insert","lines":["t"]}],[{"start":{"row":132,"column":11},"end":{"row":132,"column":12},"action":"remove","lines":["t"],"id":45}],[{"start":{"row":132,"column":11},"end":{"row":132,"column":12},"action":"insert","lines":["y"],"id":46}],[{"start":{"row":138,"column":15},"end":{"row":138,"column":17},"action":"remove","lines":["in"],"id":47},{"start":{"row":138,"column":15},"end":{"row":138,"column":16},"action":"insert","lines":["p"]},{"start":{"row":138,"column":16},"end":{"row":138,"column":17},"action":"insert","lines":["l"]},{"start":{"row":138,"column":17},"end":{"row":138,"column":18},"action":"insert","lines":["a"]},{"start":{"row":138,"column":18},"end":{"row":138,"column":19},"action":"insert","lines":["y"]}],[{"start":{"row":141,"column":33},"end":{"row":141,"column":34},"action":"remove","lines":["n"],"id":48},{"start":{"row":141,"column":32},"end":{"row":141,"column":33},"action":"remove","lines":["i"]}],[{"start":{"row":141,"column":32},"end":{"row":141,"column":33},"action":"insert","lines":["p"],"id":49},{"start":{"row":141,"column":33},"end":{"row":141,"column":34},"action":"insert","lines":["l"]},{"start":{"row":141,"column":34},"end":{"row":141,"column":35},"action":"insert","lines":["a"]},{"start":{"row":141,"column":35},"end":{"row":141,"column":36},"action":"insert","lines":["y"]}],[{"start":{"row":151,"column":17},"end":{"row":151,"column":18},"action":"insert","lines":["a"],"id":50},{"start":{"row":151,"column":18},"end":{"row":151,"column":19},"action":"insert","lines":["c"]},{"start":{"row":151,"column":19},"end":{"row":151,"column":20},"action":"insert","lines":["k"]}],[{"start":{"row":133,"column":10},"end":{"row":133,"column":11},"action":"insert","lines":["t"],"id":51},{"start":{"row":133,"column":11},"end":{"row":133,"column":12},"action":"insert","lines":["a"]},{"start":{"row":133,"column":12},"end":{"row":133,"column":13},"action":"insert","lines":["c"]},{"start":{"row":133,"column":13},"end":{"row":133,"column":14},"action":"insert","lines":["k"]}],[{"start":{"row":151,"column":17},"end":{"row":151,"column":18},"action":"insert","lines":["t"],"id":52}],[{"start":{"row":157,"column":51},"end":{"row":157,"column":52},"action":"insert","lines":["a"],"id":53},{"start":{"row":157,"column":52},"end":{"row":157,"column":53},"action":"insert","lines":["c"]},{"start":{"row":157,"column":53},"end":{"row":157,"column":54},"action":"insert","lines":["k"]}],[{"start":{"row":157,"column":51},"end":{"row":157,"column":52},"action":"insert","lines":["t"],"id":54}],[{"start":{"row":157,"column":113},"end":{"row":157,"column":114},"action":"remove","lines":["e"],"id":55},{"start":{"row":157,"column":112},"end":{"row":157,"column":113},"action":"remove","lines":["d"]}],[{"start":{"row":157,"column":112},"end":{"row":157,"column":113},"action":"insert","lines":["t"],"id":56},{"start":{"row":157,"column":113},"end":{"row":157,"column":114},"action":"insert","lines":["a"]},{"start":{"row":157,"column":114},"end":{"row":157,"column":115},"action":"insert","lines":["r"]},{"start":{"row":157,"column":115},"end":{"row":157,"column":116},"action":"insert","lines":["g"]},{"start":{"row":157,"column":116},"end":{"row":157,"column":117},"action":"insert","lines":["e"]},{"start":{"row":157,"column":117},"end":{"row":157,"column":118},"action":"insert","lines":["t"]}],[{"start":{"row":162,"column":51},"end":{"row":162,"column":52},"action":"insert","lines":["a"],"id":57}],[{"start":{"row":162,"column":51},"end":{"row":162,"column":52},"action":"remove","lines":["a"],"id":58}],[{"start":{"row":162,"column":51},"end":{"row":162,"column":52},"action":"insert","lines":["t"],"id":59},{"start":{"row":162,"column":52},"end":{"row":162,"column":53},"action":"insert","lines":["a"]},{"start":{"row":162,"column":53},"end":{"row":162,"column":54},"action":"insert","lines":["c"]},{"start":{"row":162,"column":54},"end":{"row":162,"column":55},"action":"insert","lines":["k"]}],[{"start":{"row":162,"column":127},"end":{"row":162,"column":128},"action":"remove","lines":["e"],"id":60},{"start":{"row":162,"column":126},"end":{"row":162,"column":127},"action":"remove","lines":["d"]}],[{"start":{"row":162,"column":126},"end":{"row":162,"column":127},"action":"insert","lines":["t"],"id":61},{"start":{"row":162,"column":127},"end":{"row":162,"column":128},"action":"insert","lines":["a"]},{"start":{"row":162,"column":128},"end":{"row":162,"column":129},"action":"insert","lines":["r"]},{"start":{"row":162,"column":129},"end":{"row":162,"column":130},"action":"insert","lines":["g"]},{"start":{"row":162,"column":130},"end":{"row":162,"column":131},"action":"insert","lines":["e"]},{"start":{"row":162,"column":131},"end":{"row":162,"column":132},"action":"insert","lines":["t"]}],[{"start":{"row":163,"column":52},"end":{"row":163,"column":53},"action":"remove","lines":["i"],"id":62}],[{"start":{"row":163,"column":52},"end":{"row":163,"column":53},"action":"insert","lines":["a"],"id":63},{"start":{"row":163,"column":53},"end":{"row":163,"column":54},"action":"insert","lines":["t"]},{"start":{"row":163,"column":54},"end":{"row":163,"column":55},"action":"insert","lines":["t"]},{"start":{"row":163,"column":55},"end":{"row":163,"column":56},"action":"insert","lines":["a"]},{"start":{"row":163,"column":56},"end":{"row":163,"column":57},"action":"insert","lines":["c"]},{"start":{"row":163,"column":57},"end":{"row":163,"column":58},"action":"insert","lines":["k"]}],[{"start":{"row":149,"column":12},"end":{"row":149,"column":13},"action":"insert","lines":["t"],"id":64},{"start":{"row":149,"column":13},"end":{"row":149,"column":14},"action":"insert","lines":["a"]},{"start":{"row":149,"column":14},"end":{"row":149,"column":15},"action":"insert","lines":["c"]},{"start":{"row":149,"column":15},"end":{"row":149,"column":16},"action":"insert","lines":["k"]}],[{"start":{"row":136,"column":20},"end":{"row":136,"column":22},"action":"insert","lines":["()"],"id":65}],[{"start":{"row":140,"column":12},"end":{"row":140,"column":13},"action":"remove","lines":["n"],"id":66},{"start":{"row":140,"column":11},"end":{"row":140,"column":12},"action":"remove","lines":["i"]}],[{"start":{"row":140,"column":11},"end":{"row":140,"column":12},"action":"insert","lines":["p"],"id":67},{"start":{"row":140,"column":12},"end":{"row":140,"column":13},"action":"insert","lines":["l"]},{"start":{"row":140,"column":13},"end":{"row":140,"column":14},"action":"insert","lines":["a"]},{"start":{"row":140,"column":14},"end":{"row":140,"column":15},"action":"insert","lines":["y"]}],[{"start":{"row":133,"column":19},"end":{"row":134,"column":15},"action":"remove","lines":["","    int de = 1;"],"id":68}]]},"ace":{"folds":[],"scrolltop":1816.5,"scrollleft":0,"selection":{"start":{"row":133,"column":19},"end":{"row":133,"column":19},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":128,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1525091262308,"hash":"648be02b3cb8de22bcc9663337a343e5d0a43174"}