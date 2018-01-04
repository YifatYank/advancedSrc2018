/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientListCommant.cpp
 * Description : Implements the methods of the ClientListCommand
 */

#include "ClientListCommand.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

ClientListCommand::ClientListCommand(Client &client): client_(client) {
	this->name_ = "list_games";
}

string ClientListCommand::getName() {
	return this->name_;
}

bool ClientListCommand::execute(string command) {
	int hand_shake = 0;
	this->client_.sendString(command);
	string rec;
	do {
		rec = this->client_.reciveString();

		if (rec == "_red_button_") {
			cout << "The server was closed" << endl;
			exit(0);
		}

		this->client_.sendInt(hand_shake);

		cout << rec << endl;
	} while (rec != " ");
	return false;
}

ClientListCommand::~ClientListCommand() {}


