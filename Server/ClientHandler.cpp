/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientHandler.cpp
 * Description : Implements the methods of the ClientHandler class.
 */

#include "ClientHandler.h"
#include <stdlib.h>
#include <pthread.h>

ClientHandler::ClientHandler(SocketManager * sockets , ThreadManager * threads) {
	this->sockets_ = sockets;
	this->threads_ = threads;
	this->games_ = new GameMaster();
	this->commandsSet_= new CommandsManager(*(this->games_), this->sockets_);
}

void ClientHandler::handleClient(int client_socket){
	ParamsToHandleCLientThread * params = (ParamsToHandleCLientThread *)malloc(sizeof(ParamsToHandleCLientThread ));
	params->client_socket_ = client_socket;
	params->handler_= this;
	int errno;
	pthread_t threadno;
	// Create the thread and send the arguments to it.
	errno = pthread_create(&threadno, NULL, ClientHandler::handleCLientThread, (void *) params);

	this->threads_->addThread(threadno);
/*// Read from the client his command
	char buffer[BUFFER_SIZE];
	int err;
	bool started= false;
	do {
		for(int index = 0; index < BUFFER_SIZE; ++index){
			buffer[index] = 0;
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
		string command_name = strings.front();
		strings.erase(strings.begin());

		// Puts the client socket in the command params
		string client_socket_String = this->intToString(client_socket);
		strings.push_back(client_socket_String);

		// Execute the command
		started = this->commandsSet_->ExecuteCommand(command_name, strings);
	} while (!started);*/
}

ClientHandler::~ClientHandler() {
	free(this->commandsSet_);
	free(this->games_);
}

CommandsManager * ClientHandler::getCommandSet(){
	return this->commandsSet_;
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

void * ClientHandler::handleCLientThread(void * params){
	ParamsToHandleCLientThread * handle_params = (ParamsToHandleCLientThread *)params;

	// Read from the client his command
	char buffer[BUFFER_SIZE];
	int err;
	bool started= false;
	do {
		for(int index = 0; index < BUFFER_SIZE; ++index){
			buffer[index] = 0;
		}

		err = read(handle_params->client_socket_, buffer, BUFFER_SIZE);
		if (err == -1) {
			cout << "Error (reading num1)" << endl;
			return NULL;
		}
		if (err == 0) {
			cout << "Client 1 disconnected" << endl;
			return NULL;
		}

		// Separate the client command in to words
		vector<string> strings = handle_params->handler_->splitedString(string(buffer),' ');

		// Takes the command name out of the splitedString
		string command_name = strings.front();
		strings.erase(strings.begin());

		// Puts the client socket in the command params
		string client_socket_String =
				handle_params->handler_->intToString(handle_params->client_socket_);
		strings.push_back(client_socket_String);

		// Execute the command
		started = handle_params->handler_->getCommandSet()->ExecuteCommand(command_name, strings);
	} while (!started);
	free(handle_params);
	pthread_exit(NULL);
return NULL;
}



GameMaster *ClientHandler::getGameMaster(){
	return this->games_;
}
