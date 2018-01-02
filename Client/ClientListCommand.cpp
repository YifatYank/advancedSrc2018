/*
 * ClientListCommand.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: shomps
 */

#include "ClientListCommand.h"
//#include <vector>
#include <iostream>

using namespace std;

ClientListCommand::ClientListCommand(Client &client): client_(client) {
	this->name_ = "list_games";
}

string ClientListCommand::getName() {
	return this->name_;
}

bool ClientListCommand::execute(string command) {
	this->client_.sendString(command);
	string rec;
	do {
		rec = this->client_.reciveString();
		cout << rec << endl;
	} while (rec != "");
	return false;
}

ClientListCommand::~ClientListCommand() {}


