/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientCommant.cpp
 * Description : Implements the methods of the ClientStartCommand
 */

#include "ClientStartCommand.h"
#include "RemotePlayer.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

ClientStartCommand::ClientStartCommand(Client &client, Player ** player) :
		client_(client) {
	this->name_ = "start";
	this->player = player;
}

string ClientStartCommand::getName() {
	return this->name_;
}

bool ClientStartCommand::execute(string command) {
	string err;
	string message;
	this->client_.sendString(command);
	err = client_.reciveString();

	// If the server was closed
	if (err == "_red_button_") {
		cout << "The server was closed" << endl;
		exit(0);
	}

	// If the game has created
	if (err == "0") {
		*(this->player) = new RemotePlayer(WHITE, *Client::getInctance());
		//wait for a handshake from the server.
		//the handshake confirms another player has joined
	//do {
		message = this->client_.reciveString();
		// If the server was closed
		if (err == "_red_button_") {
			cout << "The server was closed" << endl;
			exit(0);
		}
	//}while(message[0] != 'h' );
	return true;
}
return false;
}

ClientStartCommand::~ClientStartCommand() {
}

