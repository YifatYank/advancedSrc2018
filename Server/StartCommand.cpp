/*
 * StartCommand.cpp
 *
 *  Created on: Dec 30, 2017
 *      Author: yifat
 */

#include "StartCommand.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

StartCommand::StartCommand(GameMaster & games_master) :
		games_(games_master) {
	this->name_ = "start";
}

void StartCommand::execute(vector<string> args) {
	int err, return_code = 0;
	string game_name = args.back();
	args.back();
	string client_socket_str = args.back();
	int client_socket = this->string_to_int(client_socket_str);

	Game game = this->games_.startGame(game_name, client_socket);
	if (game.name_ == "" && game.socket_ == -1) {
		// Write to the client the the creation of the new game has failed.
		return_code = -1;
	}

	// Returns to the client if the game has started.
	err = write(client_socket, &return_code, sizeof(return_code));
	if (err == -1) {
		throw "Error (writing num1)";
		return;
	}
}

string StartCommand::getName() {
	return this->name_;
}

StartCommand::~StartCommand() {
}

