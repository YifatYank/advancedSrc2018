/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientJoinCommant.cpp
 * Description : Implements the methods of the ClientJoinCommand
 */

#include "ClientJoinCommand.h"
#include "RemotePlayer.h"
#include <iostream>
#include <stdlib.h>

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
	string res = this->client_.reciveString();
	// If the server was closed
	if (res == "_red_button_") {
		cout << "The server was closed" << endl;
		exit(0);
	}

	if (res == "0") {
		*(this->player_) = new RemotePlayer(BLACK, *Client::getInctance());
		return true;
	}
	return false;
}
ClientJoinCommand::~ClientJoinCommand() {
}
