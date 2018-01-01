/*
 * CommandManager.cpp
 *
 *  Created on: Dec 28, 2017
 *      Author: yifat
 */

#include "CommandsManager.h"

CommandsManager::CommandsManager(GameMaster & gamesList) : games_(gamesList) {

}

void CommandsManager::ExecuteCommand(string command, vector<string> args){
	Command * command_to_do = this->command_map_[command];
	command_to_do->execute(args);
}

CommandsManager::~CommandsManager() {
	map<string, Command *>::iterator it;
	for(it = this->command_map_.begin(); it != this->command_map_.end(); it++){
		delete it->second;
	}
}
