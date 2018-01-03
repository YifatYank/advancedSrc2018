/*
 * CommandManager.cpp
 *
 *  Created on: Dec 28, 2017
 *      Author: yifat
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
