#ifndef BATTLEFORHONOUR_COMMAND_H
#define BATTLEFORHONOUR_COMMAND_H


#include <string>
#include <memory>
#include <sstream>
#include "../../Logs/log.h"
#include "../../GameState.h"
#include "CommandSnapshot.h"

class Command {

public:

    virtual void execute(GameState &gameInfo){}
    [[nodiscard]] virtual CommandSnapshot *getSnapshot() const {
        return new CommandSnapshot("wrong command\n");
    }
    virtual ~Command(){}

};


class CommandHandler{

protected:
    CommandHandler *next{};

public:

    virtual std::unique_ptr<Command> handle(std::vector<std::string> &terminal)=0;
    virtual bool canHandle(std::vector<std::string> &terminal)=0;
    void setNext(CommandHandler *commandHandler){
        next = commandHandler;
    }
    virtual ~CommandHandler()= default;

};

int convertStr(const std::string& s) {

    try {
        return (int)std::stoull(s);
    } catch (std::invalid_argument) {
        game::log << "Wrong format. No numbers." << game::logend;
        return 0;
    } catch (std::out_of_range) {
        game::log << "Wrong format. Range overflow." << game::logend;
        return 0;
    } catch (...) {
        game::log << "Wrong format. Anything goes wrong..." << game::logend;
        return 0;
    }

}


#endif //BATTLEFORHONOUR_COMMAND_H
