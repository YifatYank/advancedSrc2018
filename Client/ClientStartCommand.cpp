/*
 * ClientStartCommand.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: yifat
 */

#include "ClientStartCommand.h"
#include "RemotePlayer.h"

ClientStartCommand::ClientStartCommand(Client &client, Player ** player): client_(client) {
	this->name_= "start";
	this->player = player;
}

string ClientStartCommand::getName(){
	return this->name_;
}

bool ClientStartCommand::execute(string command) {
	int err;
	string message;
	this->client_.sendString(command);
	err =  client_.reciveInt();

	// If the game has created
	if(err == 0){
		*(this->player) = new RemotePlayer(WHITE, *Client::getInctance());
		//wait for a handshake from the server.
		//the handshake confirms another player has joined
		message = this->client_.reciveString();
		return true;
	}
	return false;
}

ClientStartCommand::~ClientStartCommand() {}

