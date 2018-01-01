/*
 * ListCommand.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: shomps
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
void ListCommand::execute(vector<string> args) {
	string client_socket_str = args.back();
	int client_socket = this->string_to_int(client_socket_str);
	vector<string> names = this->games_.getGames();
	vector<string>::iterator it;
	const char * str_to_send = "Current Games: \n";
	int err = write(client_socket, &str_to_send, sizeof(str_to_send));
	if (err == -1) {
		throw "Error (writing message to socket)";
	}
	for (it = names.begin(); it != names.end(); it ++) {
		const char * str_to_send = (*it).c_str();
		//write argument to socket
		int err = write(client_socket, &str_to_send, sizeof(str_to_send));
		if (err == -1) {
			throw "Error (writing name to socket)";
		}
	}
}

string ListCommand::getName() {
	return this->name_;
}

ListCommand::~ListCommand() {}
