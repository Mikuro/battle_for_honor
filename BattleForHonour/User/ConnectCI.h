#ifndef BATTLEFORHONOUR_CONNECTCI_H
#define BATTLEFORHONOUR_CONNECTCI_H


#include "Commands/Command.h"

#include "Commands/AttackCommand.h"
#include "Commands/CreateCommand.h"
#include "Commands/MoveCommand.h"
#include "Commands/ShowCommand.h"
#include "Commands/ExitCommand.h"
#include "Commands/NewCommand.h"

class ConnectCI {

private:

    AttackCommandHandler *attackHandler;
    CreateCommandHandler *createHandler;
    MoveCommandHandler *moveHandler;
    ShowCommandHandler *showHandler;
    ExitCommandHandler *exitHandler;
    NewCommandHandler *newHandler;

public:

    ConnectCI(){

        attackHandler = new AttackCommandHandler();
        createHandler = new CreateCommandHandler();
        moveHandler = new MoveCommandHandler();
        showHandler = new ShowCommandHandler();
        exitHandler = new ExitCommandHandler();
        newHandler = new NewCommandHandler();


        attackHandler->setNext(createHandler);
        createHandler->setNext(moveHandler);
        moveHandler->setNext(showHandler);
        showHandler->setNext(exitHandler);
        exitHandler->setNext(newHandler);
    }

    CommandPtr handle(std::string commandString){

        std::vector <std::string> commandSplitted;
        std::stringstream ss(commandString);
        std::string commandWord;
        while (ss >> commandWord)
            commandSplitted.push_back(commandWord);

        return attackHandler->handle(commandSplitted);

    }

    ~ConnectCI(){

        delete attackHandler;
        delete createHandler;
        delete moveHandler;
        delete showHandler;
        delete exitHandler;

    }


};


#endif //BATTLEFORHONOUR_CONNECTCI_H
