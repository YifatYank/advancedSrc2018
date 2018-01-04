/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : CommandsManager.cpp
 * Description : Implements the methods of CommandsManager
 */

#include "CommandsManager.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "ListCommand.h"
#include "Command.h"

CommandsManager::CommandsManager(GameMaster & gamesList, SocketManager * sockets) :
		games_(gamesList) {
	//HEAD

	Command * command = new StartCommand(this->games_);
	this->command_map_[command->getName()] = command;
	command = new JoinCommand(this->games_, sockets);
	this->command_map_[command->getName()] = command;
	command = new ListCommand(this->games_);
	this->command_map_[command->getName()] = command;
}

bool CommandsManager::ExecuteCommand(string command, vector<string> args) {
	Command * command_to_do = this->command_map_[command];
	return command_to_do->execute(args);
}

CommandsManager::~CommandsManager() {
	map<string, Command *>::iterator it;
	for (it = this->command_map_.begin(); it != this->command_map_.end();
			it++) {
		delete it->second;
	}
}
