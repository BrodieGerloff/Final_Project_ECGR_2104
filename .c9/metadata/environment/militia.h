{"filter":false,"title":"militia.h","tooltip":"/militia.h","undoManager":{"mark":1,"position":1,"stack":[[{"start":{"row":0,"column":0},"end":{"row":23,"column":6},"action":"insert","lines":["#ifndef MILITIA_H","#define MILITIA_H","","#include <iostream>","#include \"card.h\"","","using namespace std;","","class Militia : public Card {","    private:","    ","    public:","    ","    Militia(void);","    virtual string render(int);","};","","militia :: card(){","\tmanaCost = 1;","\tattack = 100;","\tdefense = 300","}","","#endif"],"id":1}],[{"start":{"row":17,"column":0},"end":{"row":21,"column":1},"action":"remove","lines":["militia :: card(){","\tmanaCost = 1;","\tattack = 100;","\tdefense = 300","}"],"id":2}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":17,"column":0},"end":{"row":17,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1524248582288,"hash":"e877bd330009b548b42afbb607569e30ecefcb25"}