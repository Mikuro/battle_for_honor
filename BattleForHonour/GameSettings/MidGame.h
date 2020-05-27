#ifndef BATTLEFORHONOUR_MIDGAME_H
#define BATTLEFORHONOUR_MIDGAME_H


#include "GameRule.h"
#include "PlayerState.h"

class MidGame: public GameRule {

private:

    PlayerState* nowState;

public:

    MidGame(): GameRule(10, 10), nowState(new FirstPlayer){}

    bool isOver(GameInfo &gameInfo) override {
        return false;
    }

       int nextUser(GameInfo &gameInfo) override {

       int nowPlayerIndex = gameInfo.getNowPlayerIndex()+nowState->getNextPlayerDelta();
       nowPlayerIndex %= gameInfo.getBases().size();
       auto nextState = nowState->getNextPlayerState();
       delete nowState;
       nowState = nextState;
       if (nowState == nullptr)
           nowState = new FirstPlayer;
       return nowPlayerIndex;

    }

};


#endif //BATTLEFORHONOUR_MIDGAME_H
