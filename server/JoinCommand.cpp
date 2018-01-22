/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : JoinCommand.cpp
 * Description : Implements the methods of JoinCommand
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

JoinCommand::JoinCommand(GameMaster & games_master, SocketManager * sockets, ThreadManager * threads) :
		games_(games_master) {
	this->name_ = "join";
	this->sockets_ = sockets;
	this->threads_ = threads;
}

bool JoinCommand::execute(vector<string> args) {
	string game_name = args.front();
	string client_socket_str = args.back();
	int client_socket = this->string_to_int(client_socket_str);
	char return_value[2];
	return_value[1] = 0;

	// Get from the game master the game the user want to join.
	Game game = this->games_.joinGame(game_name);

	// If the game is a legal game
	if (game.name_ != "" && game.socket_ != -1) {
		return_value[0] = '0';
	} else {
		return_value[0] = '1';
	}

	int err = 0;

	err = write(client_socket, return_value, 1);
	if (err == -1) {
		throw "Error (writing num2)";
		exit(-1);
	}

	if (return_value[0] == '1') {
		return false;
	}

	int client_socket1 = game.socket_;
	int client_socekt2 = client_socket;

	// Move the socket to the "in game" socket list
	this->sockets_->addToGame(client_socket1);
	this->sockets_->addToGame(client_socekt2);

	//notify first player that the game may begin
	char handshake[2];
	handshake[0] = '0';
	handshake[1] = 0;
	err = write(client_socket1, handshake, 1);
	if (err == -1) {
		throw "Error (handshake)";
		exit(-1);
	}

	// Make the game to be handle by an other thread out of the thread pull.
	params_to_join_command_thread * params =
			(params_to_join_command_thread *) malloc(
					sizeof(params_to_join_command_thread));
	params->client_socket1 = client_socket1;
	params->client_sokcet2 = client_socekt2;
	params->command = this;

	pthread_t threano = 0;
	pthread_create(&threano, NULL, executeThread, (void *) params);

	this->threads_->addThread(threano);
	return true;

	/*
	 *
	 *
	 *
	 // todo - turn to a threadcl
	 int num1, num2;
	 while (true) {
	 //read new arguments from client1
	 err = read(client_socket1, &num1, sizeof(num1));
	 if (err == -1) {
	 throw "Error (reading num1)";
	 return false;
	 }
	 if (err == 0) {
	 break;
	 }
	 err = read(client_socket1, &num2, sizeof(num2));
	 if (err == -1) {
	 throw "Error (reading num2)";
	 exit(-1);
	 }

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
	 break;
	 }
	 err = read(client_socekt2, &num2, sizeof(num2));
	 if (err == -1) {
	 throw "Error (reading num2)";
	 exit(-1);
	 }

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
	 this->sockets_->removeSocket(client_socket1);
	 close(client_socekt2);
	 this->sockets_->removeSocket(client_socekt2);
	 return true;*/
}

void * JoinCommand::executeThread(void * params) {
	// todo - turn to a threadcl
	params_to_join_command_thread * parameters =
			(params_to_join_command_thread *) params;
	int client_socket1 = parameters->client_socket1;
	int client_socekt2 = parameters->client_sokcet2;
	JoinCommand * command = parameters->command;

	free(parameters);

	int num1, num2, err;
	while (true) {
		//read new arguments from client1
		err = read(client_socket1, &num1, sizeof(num1));
		if (err == -1) {
			throw "Error (reading num1)";
			return NULL;
		}
		if (err == 0) {
			break;
		}
		err = read(client_socket1, &num2, sizeof(num2));
		if (err == -1) {
			throw "Error (reading num2)";
			exit(-1);
		}

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
			break;
		}
		err = read(client_socekt2, &num2, sizeof(num2));
		if (err == -1) {
			throw "Error (reading num2)";
			exit(-1);
		}

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
	command->sockets_->removeSocket(client_socket1);
	close (client_socekt2);
	command->sockets_->removeSocket(client_socekt2);
	return NULL;
}

string JoinCommand::getName() {
	return this->name_;
}

JoinCommand::~JoinCommand() {
}

