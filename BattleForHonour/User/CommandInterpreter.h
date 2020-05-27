#ifndef BATTLEFORHONOUR_COMMANDINTERPRETER_H
#define BATTLEFORHONOUR_COMMANDINTERPRETER_H


#include "Commands/Command.h"

#include "Commands/AttackCommand.h"
#include "Commands/CreateCommand.h"
#include "Commands/MoveCommand.h"
#include "Commands/ShowCommand.h"
#include "Commands/ExitCommand.h"
#include "Commands/SaveCommand.h"
#include "Commands/LoadCommand.h"
#include "Commands/NewCommand.h"

class CommandInterpreter {

private:

    AttackCommandHandler *attackHandler;
    CreateCommandHandler *createHandler;
    MoveCommandHandler *moveHandler;
    ShowCommandHandler *showHandler;
    ExitCommandHandler *exitHandler;
    SaveCommandHandler *saveHandler;
    LoadCommandHandler *loadHandler;
    NewCommandHandler *newHandler;

public:

    CommandInterpreter(){

        attackHandler = new AttackCommandHandler();
        createHandler = new CreateCommandHandler();
        moveHandler = new MoveCommandHandler();
        showHandler = new ShowCommandHandler();
        exitHandler = new ExitCommandHandler();
        saveHandler = new SaveCommandHandler();
        loadHandler = new LoadCommandHandler();
        newHandler = new NewCommandHandler();

        attackHandler->setNext(createHandler);
        createHandler->setNext(moveHandler);
        moveHandler->setNext(showHandler);
        showHandler->setNext(exitHandler);
        exitHandler->setNext(saveHandler);
        saveHandler->setNext(loadHandler);
        loadHandler->setNext(newHandler);
    }

    CommandPtr handle(std::string commandString){

        std::vector <std::string> commandSplitted;
        std::stringstream ss(commandString);
        std::string commandWord;
        while (ss >> commandWord)
            commandSplitted.push_back(commandWord);

        return attackHandler->handle(commandSplitted);

    }

    ~CommandInterpreter(){

        delete attackHandler;
        delete createHandler;
        delete moveHandler;
        delete showHandler;
        delete exitHandler;
        delete saveHandler;

    }

};

#endif //BATTLEFORHONOUR_COMMANDINTERPRETER_H
