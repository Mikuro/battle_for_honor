#include <iostream>
#include "GameFacade.h"
#include "Logs/TimeFormat.h"
#include "Logs/FileLogger.h"
#include "Logs/TerminalLogger.h"
#include "GameSettings/BigGame.h"
#include "GameSettings/SmallGame.h"

int main() {

    game::log.setLogger(new TerminalLogger());
    game::log.setLogFormat(new TimeFormat());

    auto game = GameFacade<BigGame, 2>::instance();

    while (!game.isOver()){

        std::cout << game;
        game.nextTurn();

    }

    return 0;
}