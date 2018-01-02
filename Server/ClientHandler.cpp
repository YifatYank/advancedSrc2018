/*
 * ClientHandler.cpp
 *
 *  Created on: Dec 28, 2017
 *      Author: yifat
 */

#include "ClientHandler.h"
#include <stdlib.h>


ClientHandler::ClientHandler() {
	this->games_ = new GameMaster();
	this->commandsSet_= new CommandsManager(*(this->games_));
}

void ClientHandler::handleClient(int client_socket){
	// Read from the client his command
	char buffer[BUFFER_SIZE];
	int err;

	for(int index = 0; index < BUFFER_SIZE; ++index){
		buffer[index] = '0';
	}

	err = read(client_socket, buffer, BUFFER_SIZE);
	if (err == -1) {
		cout << "Error (reading num1)" << endl;
		return;
	}
	if (err == 0) {
		cout << "Client 1 disconnected" << endl;
		return;
	}

	// Separate the client command in to words
	vector<string> strings = this->splitedString(string(buffer),' ');

	// Takes the command name out of the splitedString
	string command_name = strings.back();
	strings.pop_back();

	// Puts the client socket in the command params
	string client_socket_String = this->intToString(client_socket);
	strings.push_back(client_socket_String);

	// Execute the command
	this->commandsSet_->ExecuteCommand(command_name, strings);
}

ClientHandler::~ClientHandler() {
	free(this->commandsSet_);
	free(this->games_);
}

vector<string> ClientHandler::splitedString(string string_to_split, char delim){
	vector<string> strings;
	int size = string_to_split.size();
	string str = "";
	for(int index = 0; index < size; index++) {
		if(string_to_split[index] !=' '){
			str += string_to_split[index];
		} else{
			strings.push_back(str);
			str = "";
		}
	}
	if(str.size() != 0){
		strings.push_back(str);
	}

	return strings;
}

string ClientHandler::intToString(int num){
	string str = "";
	int digit;
	char char_digit;

	if(num == 0){
		return 0;
	}
	if(num < -1){
		str += '-';
		num = num * -1;
	}

	while(num != 0){
		digit = num % 10;
		char_digit = char(digit);
		char_digit += 48;
		str += char_digit;
		num /= 10;
	}

	return str;
}
