/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : StartCommand.cpp
 * Description : Implements the methods of StartCommand
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

bool StartCommand::execute(vector<string> args) {
	int err;
	char  return_code[2];
	return_code[1]= 0;
	return_code[0] = '0';
	string game_name = args.front();
	string client_socket_str = args.back();
	int client_socket = this->string_to_int(client_socket_str);

	Game game = this->games_.startGame(game_name, client_socket);
	if (game.name_ == "" && game.socket_ == -1) {
		// Write to the client the the creation of the new game has failed.
		return_code[0] = '1';
	}

	// Returns to the client if the game has started.
	err = write(client_socket, return_code, 1);
	if (err == -1) {
		throw "Error (writing num1)";
		return false;
	}

	return (return_code[0] == '1' ? false : true);
}

string StartCommand::getName() {
	return this->name_;
}

StartCommand::~StartCommand() {
}

