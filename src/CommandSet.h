#ifndef __COMMAND_SET_H__
#define __COMMAND_SET_H__

#include <map>
#include <vector>
#include <string>

#include "Command.h"

namespace cigma
{
    class CommandSet;
}

/**
 * @brief Container for a set of commands
 *
 */
class cigma::CommandSet
{
public:
    typedef std::map<std::string,Command*> CmdMap;
    typedef std::vector<std::string> CmdNames;

public:
    CommandSet();
    ~CommandSet();

public:
    void initialize();
    int main(int argc, char *argv[]);

public:
    void addCommand(Command *cmd);
    Command *getCommand(std::string name);

public:
    CmdNames names;
    CmdMap commands;
};

#endif
