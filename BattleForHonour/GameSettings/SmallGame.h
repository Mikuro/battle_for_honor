#ifndef BATTLEFORHONOUR_SMALLGAME_H
#define BATTLEFORHONOUR_SMALLGAME_H


#include "GameRule.h"
#include "PlayerState.h"

class SmallGame: public GameRule {

private:

    PlayerState* nowState;

public:

    SmallGame(): GameRule( 5, 5), nowState(new FirstPlayer){}

    bool isOver(GameState &gameInfo) override {
        int liveCount = gameInfo.getBases().size();
        for (auto b: gameInfo.getBases()){
            if (b && b->getHealth() <= 0){
                liveCount--;
            }
        }

        return liveCount <= 1;
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

#endif //BATTLEFORHONOUR_SMALLGAME_H
