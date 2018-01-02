/*
 * ClientCommandsManager.cpp
 *
 *  Created on: Jan 1, 2018
 *      Author: shomps
 */

#include "ClientCommandsManager.h"
#include "ClientStartCommand.h"
#include "ClientJoinCommand.h"
#include "ClientListCommand.h"

ClientCommandsManager::ClientCommandsManager(Client &client, Player **player) {
	ClientCommand * command = new ClientStartCommand(client, player);
	this->command_map_[command->getName()] = command;
	command = new ClientJoinCommand(client, player);
	this->command_map_[command->getName()] = command;
	command = new ClientListCommand(client);
	this->command_map_[command->getName()] = command;
}

bool ClientCommandsManager::ExecuteCommand(string command) {
	vector<string> strings = this->splitedString(command,' ');
	string command_name = strings.front();
	ClientCommand * command_to_do = this->command_map_[command_name];
	return (command_to_do->execute(command));
}

vector<string> ClientCommandsManager::splitedString(string string_to_split, char delim){
	vector<string> strings;
	int size = string_to_split.size();
	string str = "";
	for(int index = 0; index < size; index++) {
		if(string_to_split[index] !=' '){
			str += string_to_split[index];
		} else{
			strings.push_back(str);
			str = "";
		}
	}
	if(str.size() != 0){
		strings.push_back(str);
	}

	return strings;
}

ClientCommandsManager::~ClientCommandsManager() {
	map<string, ClientCommand *>::iterator it;
	for(it = this->command_map_.begin(); it != this->command_map_.end(); it++){
		delete it->second;
	}
}
