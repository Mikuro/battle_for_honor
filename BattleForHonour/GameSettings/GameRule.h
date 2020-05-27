#ifndef BATTLEFORHONOUR_GAMERULE_H
#define BATTLEFORHONOUR_GAMERULE_H


class GameInfo;

class GameRule {

public:
    int fieldWidth;
    int fieldHeight;
    virtual bool isOver(GameInfo &gameInfo)=0;
    virtual int nextUser(GameInfo &gameInfo)=0;

    GameRule(int fieldWidth, int fieldHeight):
            fieldWidth(fieldWidth),
            fieldHeight(fieldHeight){}

};

#endif //BATTLEFORHONOUR_GAMERULE_H
