/*
 * CommandManager.h
 *
 *  Created on: Dec 28, 2017
 *      Author: yifat
 */

#ifndef COMMANDSMANAGER_H_
#define COMMANDSMANAGER_H_

#include <string>
#include <map>
#include "Command.h"
#include "GameMaster.h"
using namespace std;

class CommandsManager {
private:
	map<string, Command *> command_map_;
	GameMaster & games_;
public:
	CommandsManager(GameMaster & gamesList);
	bool ExecuteCommand(string command, vector<string> args);
	virtual ~CommandsManager();
};

#endif /* COMMANDSMANAGER_H_ */
