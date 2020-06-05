#ifndef BATTLEFORHONOUR_GAMERULE_H
#define BATTLEFORHONOUR_GAMERULE_H


class GameState;

class GameRule {

public:
    int fieldWidth;
    int fieldHeight;
    virtual bool isOver(GameState &gameInfo)=0;
    virtual int nextUser(GameState &gameInfo)=0;

    GameRule(int fieldWidth, int fieldHeight):
            fieldWidth(fieldWidth),
            fieldHeight(fieldHeight){}

};

#endif //BATTLEFORHONOUR_GAMERULE_H
