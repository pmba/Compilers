/****************************

ALLUPH - Analisador Lexico e Sintatico
Phyllipe Matheus Bezerra Alves
Lucas Agra de Omena
Universidade Federal de Alagoas
Ciencia da Computacao

*****************************/

#define NonTerminalQuant 41
#define TerminalsQuant 49

#define POP -1
#define ERROR -2


int preditive_table[NonTerminalQuant][TerminalsQuant] = {
    
    {1 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2},
    {2 ,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3 },
    {-1,-1,-1,4 ,5 ,-1,-1,-1,-1,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-2,-2,6 ,7 ,8 ,9 ,10,-1,-1,-1,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-2,-2,11,11,11,11,11,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,14,-1,14,14,14,14,14,-1,14,16,15,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,14,-1,-1,14,-1,-1,-1,-1,14,14,14,14,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,18,-1,17,17,17,17,17,-1,18,-2,-1,18,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,18,-1,-1,18,-1,-1,-1,-1,18,18,18,18,-1,-1,-1,-1,-1,-1},
    {-1,-1,-2,19,-1,19,19,19,19,19,-1,-1,-1,-1,19,19,19,19,-1,-1,-1,-1,-1,-1,-1,19,19,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,21,20,-1,20,20,20,20,20,-1,-1,-1,-1,20,20,20,20,-1,-1,-1,-1,-1,-1,-1,20,20,20,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-2,29,-1,25,25,25,25,25,-1,-1,-1,-1,26,22,23,24,-1,-1,-1,-1,-1,-1,-1,27,28,30,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,32,32,-1,32,32,32,32,32,-1,-1,-1,-1,32,32,32,32,-1,31,-1,-1,-1,-1,-1,32,32,32,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-2,-2,-1,35,35,35,35,35,-1,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,-2,-1,-2,-2,-2,-2,-2,-1,-2,-2,-2,36,-1,-1,-1,-2,-1,-2,-2,-1,-2,-2,-1,-1,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1},
    {-1,38,-1,38,-1,38,38,38,38,38,-1,38,38,38,38,-1,-1,-1,38,-1,38,38,37,38,38,-1,-1,-1,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,-1},
    {-1,-2,-2,-2,-1,-2,-2,-2,-2,-2,-1,-1,-1,-1,39,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-2,-2,-1,-2,-2,-2,-2,-2,-1,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,40,-2,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-2,-2,-1,-2,-2,-2,-2,-2,-1,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-2,41,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-2,-2,42,-1,-2,-2,-2,-2,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-1,-2,-2,-1,-2,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-1},
    {-1,-1,-2,-2,-1,-2,-2,-2,-2,-2,-1,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1,-1,-2,-2,43,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,44,-1,-2,-2,-2,-2,-2,-1,44,-2,-2,44,-1,-1,-1,-1,-1,-1,-2,-1,-2,-1,-1,-1,-1,-1,-1,-1,44,-1,-1,44,-1,-1,-1,-1,44,44,44,44,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,46,-1,46,46,46,46,46,-1,46,46,46,46,-1,-1,-1,-1,-1,-1,46,-1,46,-1,-1,-1,-1,45,-1,-1,46,-1,-1,46,-1,-1,-1,-1,46,46,46,46,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,47,-1,-2,-2,-2,-2,-2,-1,47,-2,-2,47,-1,-1,-1,-2,-1,-1,-2,-1,-2,-1,-1,-1,-1,-2,-1,-1,47,-1,-1,47,-1,-1,-1,-1,47,47,47,47,-1,-1,-1,-1,-1,-1},
    {-1,49,-1,49,-1,49,49,49,49,49,-1,49,49,49,49,-1,-1,-1,49,-1,-1,49,-1,49,-1,-1,-1,-1,49,48,-1,49,-1,-1,49,-1,-1,-1,-1,49,49,49,49,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,50,-1,-2,-2,-2,-2,-2,-1,50,-2,-2,50,-1,-1,-1,-2,-1,-1,-2,-1,-2,-1,-1,-1,-1,-2,-2,-1,50,-1,-1,50,-1,-1,-1,-1,50,50,50,50,-1,-1,-1,-1,-1,-1},
    {-1,52,-1,52,-1,52,52,52,52,52,-1,52,52,52,52,-1,-1,-1,52,-1,-1,52,-1,52,-1,-1,-1,-1,52,52,51,52,-1,-1,52,-1,-1,-1,-1,52,52,52,52,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,54,-1,-2,-2,-2,-2,-2,-1,54,-2,-2,54,-1,-1,-1,-2,-1,-1,-2,-1,-2,-1,-1,-1,-1,-2,-2,-2,53,-1,-1,54,-1,-1,-1,-1,54,54,54,54,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,55,-1,-2,-2,-2,-2,-2,-1,55,-2,-2,55,-1,-1,-1,-2,-1,-1,-2,-1,-2,-1,-1,-1,-1,-2,-2,-2,-2,-1,-1,55,-1,-1,-1,-1,55,55,55,55,-1,-1,-1,-1,-1,-1},
    {-1,57,-1,57,-1,57,57,57,57,57,-1,57,57,57,57,-1,-1,-1,57,-1,-1,57,-1,57,-1,-1,-1,-1,57,57,57,57,56,56,57,-1,-1,-1,-1,57,57,57,57,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-2,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,58,59,-2,-1,-1,-1,-1,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,61,-1,-2,-2,-2,-2,-2,-1,61,-2,-2,61,-1,-1,-1,-2,-1,-1,-2,-1,-2,-1,-1,-1,-1,-2,-2,-2,-2,-2,-2,60,-2,-2,-2,-2,61,61,61,61,-1,-1,-1,-1,-1,-1},
    {-1,63,-1,63,-1,63,63,63,63,63,-1,63,63,63,63,-1,-1,-1,63,-1,-1,63,-1,63,-1,-1,-1,-1,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-2,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2,64,65,66,67,-2,-2,-2,-2,-1,-1,-1,-1,-1,-1},
    {-1,-2,-1,68,-1,-2,-2,-2,-2,-2,-1,68,-2,-2,68,-1,-1,-1,-2,-1,-2,-2,-1,-2,-1,-1,-1,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,68,68,68,68,-1,-1,-1,-1,-1,-1},
    {-1,70,-1,70,-1,70,70,70,70,70,-1,70,70,70,70,-1,-1,-1,70,-1,70,70,-1,70,-1,-1,-1,-1,70,70,70,70,70,70,70,70,70,70,70,70,70,70,70,69,69,-1,-1,-1,-1},
    {-1,-2,-1,71,-1,-2,-2,-2,-2,-2,-1,71,-2,-2,71,-1,-1,-1,-2,-1,-2,-2,-1,-2,-1,-1,-1,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,71,71,71,71,-2,-2,-1,-1,-1,-1},
    {-1,73,-1,73,-1,73,73,73,73,73,-1,73,73,73,73,-1,-1,-1,73,-1,73,73,-1,73,-1,-1,-1,-1,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,73,72,72,72,-1},
    {-1,-2,-1,76,-1,-2,-2,-2,-2,-2,-1,74,-2,-2,75,-1,-1,-1,-2,-1,-2,-2,-1,-2,-1,-1,-1,-1,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,77,78,79,80,-2,-2,-2,-2,-2,-1},
    {-1,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-2,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2,-2,-2,-2,81,82,-1,-1,-1,-1},
    {-1,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-2,-1,-1,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-2,-2,-2,-2,-1,-1,83,84,85,-1}
};

typedef enum non_term {

    S = 0, 
    DefFunList, FunId, VarType, FunType, OpClPar, Par,
    ParAux, SentList, SentListAux, Sent, Else, Doing, Decl,
    Id, VecType, Atr, Print, Read, FunCall, Return, Exp,
    ExpRec, BoolExp, BoolExpRec, BoolTerm, BoolTermRec, 
    BoolFac, EqExp, EqExpAux, EqOpe, RelExp, RelExpRec, 
    RelOpe, ArExp, ArExpRec, ArTerm, ArTermRec,ArFac, 
    ArOpe, MultOpe

} NonTerminal;

typedef enum category {

    catFunction = NonTerminalQuant, 
    catDo, catEnd, catFunId, catMain, catInt,
    catFloat, catString, catBool, catChar, catVoid, catOpPar,
    catClsPar, catComma, catId, catIf, catWhile, catFrom, 
    catTo, catElse, catDoing, catSemiCol, catOpBrac, 
    catClsBrac, catOpeAtr, catPrint, catRead, carReturn, 
    catOpeConc, catOpeOr, catOpeAnd, catOpeNeg, catOpeEq, 
    catOpeDif, catCteBool, catOpeGt, catOpeGte, catOpeLt, 
    catOpeLte, catCteInt, catCteFloat, catCteStr, catCteChar, 
    catOpeSum, catOpeSub, catOpeMult, catOpeDiv, catOpeRest, 
    catEOF

} Category;