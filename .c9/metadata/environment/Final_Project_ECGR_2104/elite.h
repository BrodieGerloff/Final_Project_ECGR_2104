{"filter":false,"title":"elite.h","tooltip":"/Final_Project_ECGR_2104/elite.h","undoManager":{"mark":1,"position":1,"stack":[[{"start":{"row":0,"column":0},"end":{"row":42,"column":0},"action":"insert","lines":["#ifndef Elite_H","#define Elite_H","","#include <iostream>","#include \"card.h\"","","using namespace std;","","class Elite : public Card {","    private:","    ","    public:","    ","    Elite(void);","    virtual string render(int);","};","","#endif","#include \"elite.h\"","","","elite :: card(){","\tmanaCost = 4;","\tattack = 300;","\tdefense = 500","}","","string Elite::render(int line){","    "," switch(line){","        case 0: return \".___________.\";","        case 1: return \"|Elite      |\";","        case 2: return \"|  /-----\\  |\";","        case 3: return \"|  |+\t+|  |\";","        case 4: return \"|  |+   +|  |\";","        case 5: return \"|  \\ ___ /  |\";","        case 6: return \"|  300/500  |\";","        case 7: return \"|___________|\";","        default:","            return \" \";","    }","}",""],"id":1}],[{"start":{"row":18,"column":0},"end":{"row":42,"column":0},"action":"remove","lines":["#include \"elite.h\"","","","elite :: card(){","\tmanaCost = 4;","\tattack = 300;","\tdefense = 500","}","","string Elite::render(int line){","    "," switch(line){","        case 0: return \".___________.\";","        case 1: return \"|Elite      |\";","        case 2: return \"|  /-----\\  |\";","        case 3: return \"|  |+\t+|  |\";","        case 4: return \"|  |+   +|  |\";","        case 5: return \"|  \\ ___ /  |\";","        case 6: return \"|  300/500  |\";","        case 7: return \"|___________|\";","        default:","            return \" \";","    }","}",""],"id":2}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":18,"column":0},"end":{"row":18,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1524250469213,"hash":"caa46fe1b80b2d4f07b67a5d0e6f72e1630e5d42"}