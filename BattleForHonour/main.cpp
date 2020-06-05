#include <iostream>
#include "GameFacade.h"
#include "Logs/FileLogger.h"
#include "Logs/CmdLogger.h"
#include "GameSettings/BigGame.h"
#include "GameSettings/SmallGame.h"
#include "GameSettings/MidGame.h"

int main() {

    game::log.setLogger(new CmdLogger());
    game::log.setLogFormat(new NoFormat());

    auto game = GameFacade<MidGame, 2>::single();

    while (game.isOver() == false){
        std::cout << game;
        game.nextTurn();
    }

    return 0;
}