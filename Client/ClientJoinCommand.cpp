/*
 * ClientJoinCommand.cpp
 *
 *  Created on: Jan 1, 2018
 *      Author: shomps
 */

#include "ClientJoinCommand.h"

using namespace std;

ClientJoinCommand::ClientJoinCommand(Client &client, Player **player) :
		client_(client), player_(player) {
	this->name_ = "join";
}

string ClientJoinCommand::getName() {
	return this->name_;
}

bool ClientJoinCommand::execute(string command) {
	this->client_.sendString(command);
	int res = this->client_.reciveInt();
	return (res == 0 ? true : false);
}
ClientJoinCommand::~ClientJoinCommand() {
}
