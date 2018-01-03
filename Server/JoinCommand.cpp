/*
 * joinCommand.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: yifat
 */

#include "JoinCommand.h"

#include "StartCommand.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

JoinCommand::JoinCommand(GameMaster & games_master) :
		games_(games_master) {
	this->name_ = "join";
}

bool JoinCommand::execute(vector<string> args) {
	string game_name = args.front();
	string client_socket_str = args.back();
	int client_socket = this->string_to_int(client_socket_str);
	int return_value;

	// Get from the game master the game the user want to join.
	Game game = this->games_.joinGame(game_name);

	// If the game is a legal game
	if (game.name_ != "" && game.socket_ != -1) {
		return_value = 0;
	} else {
		return_value = -1;
	}

	int err = 0;

	err = write(client_socket, &return_value, sizeof(return_value));
	if (err == -1) {
		throw "Error (writing num2)";
		exit(-1);
	}

	if (return_value == -1) {
		return false;
	}

	int client_socket1 = game.socket_;
	int client_socekt2 = client_socket;
	//notify first player that the game may begin
	int handshake = 0;
	err = write(client_socket1, &handshake, sizeof(handshake));
	if (err == -1) {
		throw "Error (handshake)";
		exit(-1);
	}
	int num1, num2;
	while (true) {
		//read new arguments from client1
		err = read(client_socket1, &num1, sizeof(num1));
		if (err == -1) {
			throw "Error (reading num1)";
			return false;
		}
		if (err == 0) {
			cout << "Client 1 disconnected" << endl;
			//return;
			break;
			//check what to do if client 2 disconnects while client 1 is connected
		}
		err = read(client_socket1, &num2, sizeof(num2));
		if (err == -1) {
			throw "Error (reading num2)";
			exit(-1);
		}
		cout << "GOT:" << num1 << " , " << num2 << endl;

		//write numbers to client2
		err = write(client_socekt2, &num1, sizeof(num1));
		if (err == -1) {
			throw "Error (writing num1)";
			exit(-1);
		}
		err = write(client_socekt2, &num2, sizeof(num2));
		if (err == -1) {
			throw "Error (writing num2)";
			exit(-1);
		}

		//read new arguments from client2
		err = read(client_socekt2, &num1, sizeof(num1));
		if (err == -1) {
			throw "Error (reading num1)";
			exit(-1);
		}
		if (err == 0) {
			cout << "Client 2 disconnected" << endl;
			break;
		}
		err = read(client_socekt2, &num2, sizeof(num2));
		if (err == -1) {
			throw "Error (reading num2)";
			exit(-1);
		}
		cout << "GOT:" << num1 << " , " << num2 << endl;

		//write numbers to client1}
		err = write(client_socket1, &num1, sizeof(num1));
		if (err == -1) {
			throw "Error (writing num1)";
			exit(-1);
		}
		err = write(client_socket1, &num2, sizeof(num2));
		if (err == -1) {
			throw "Error (writing num2)";
			exit(-1);
		}
	}
	close(client_socket1);
	close(client_socekt2);
	return true;
}

string JoinCommand::getName() {
	return this->name_ ;
}

JoinCommand::~JoinCommand() {}

