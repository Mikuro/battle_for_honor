#ifndef BATTLEFORHONOUR_BIGGAME_H
#define BATTLEFORHONOUR_BIGGAME_H


#include "GameRule.h"
#include "PlayerState.h"

class BigGame: public GameRule {

private:

    PlayerState* nowState;

public:

    BigGame(): GameRule( 15, 15), nowState(new FirstPlayer){}

    bool isOver(GameState &gameInfo) override {
        return false;
    }

    int nextUser(GameState &gameInfo) override {
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


#endif //BATTLEFORHONOUR_BIGGAME_H
