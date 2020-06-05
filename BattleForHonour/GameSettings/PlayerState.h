#ifndef BATTLEFORHONOUR_PLAYERSTATE_H
#define BATTLEFORHONOUR_PLAYERSTATE_H


class PlayerState {

public:

    virtual int getNextPlayerDelta()=0;
    virtual PlayerState* getNextPlayerState()=0;

};

class SecondPlayer: public PlayerState {

    int getNextPlayerDelta() override{
        return 2;
    }

    PlayerState* getNextPlayerState() override{
        return nullptr;
    }

};

class SpecPlayer: public PlayerState {

    int getNextPlayerDelta() override{
        return -1;
    }

    PlayerState* getNextPlayerState() override{
        return new SecondPlayer;
    }

};

class FirstPlayer: public PlayerState {

public:

    int getNextPlayerDelta() override{
        return 2;
    }

    PlayerState* getNextPlayerState() override{

        return new SpecPlayer;

    }

};


#endif //BATTLEFORHONOUR_PLAYERSTATE_H
