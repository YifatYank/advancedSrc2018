/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ListCommand.cpp
 * Description : Implements the methods of ListCommand
 */

#include "ListCommand.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

ListCommand::ListCommand(GameMaster & games_master) :
		games_(games_master) {
	this->name_ = "list_games";
}

bool ListCommand::execute(vector<string> args) {
	string client_socket_str = args.back();
	int hand_shake;
	int client_socket = this->string_to_int(client_socket_str);
	vector<string> names = this->games_.getGames();
	vector<string>::iterator it;
	const char * str_to_send = "Current Games: \n";
	int err = write(client_socket, str_to_send, sizeof("Current Games: \n"));
	if (err == -1) {
		throw "Error (writing message to socket)";
	}
	err = read(client_socket, &hand_shake, sizeof(hand_shake));

	for (it = names.begin(); it != names.end(); it ++) {
		const char * str_to_send = (*it).c_str();
		//write argument to socket
		int err = write(client_socket, str_to_send, (*it).size());
		if (err == -1) {
			throw "Error (writing name to socket)";
		}
		err = read(client_socket, &hand_shake, sizeof(hand_shake));
	}
	return false;
}

string ListCommand::getName() {
	return this->name_;
}

ListCommand::~ListCommand() {}
