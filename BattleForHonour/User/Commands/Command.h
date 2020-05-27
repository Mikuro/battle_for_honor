#ifndef BATTLEFORHONOUR_COMMAND_H
#define BATTLEFORHONOUR_COMMAND_H


#include <string>
#include <memory>
#include <sstream>

#include "../../GameInfo.h"
#include "CommandMemento.h"

class Command {

public:

    virtual void execute(GameInfo &gameInfo){}
    virtual CommandMemento *getMemento() const { return new CommandMemento("wrong command\n"); }
    virtual ~Command(){}

};

typedef std::unique_ptr<Command> CommandPtr;

class CommandHandler{

protected:
    CommandHandler *next;

public:

    virtual CommandPtr handle(std::vector<std::string> &cmd)=0;
    virtual bool canHandle(std::vector<std::string> &cmd)=0;
    void setNext(CommandHandler *commandHandler){
        next = commandHandler;
    }

    virtual ~CommandHandler()= default;

};


#endif //BATTLEFORHONOUR_COMMAND_H
