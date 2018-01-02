/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Server.cpp
 * Description : Implements the methods of the Server class.
 */

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define BACK_LOG 10
#define PORT 8000

Server::Server(ClientHandler & client_handler): port_(PORT) , server_socket_1_(0) , handler_(client_handler){
	setConfigs();
	//cout << "SERVER CONSTRUCTED!" << endl;
}

Server::Server(int port, ClientHandler & client_handler)
		: port_(port), server_socket_1_(0) ,  handler_(client_handler) {
	setConfigs();
	//cout << "SERVER CONSTRUCTED!" << endl;
}

void Server::start() {
	int client_socket;

	// Initiating the server socket
	this->server_socket_1_ = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket_1_ == -1) {
		throw "Error (opening socket)";
		exit(-1);
	}

	//assign local address to socket
	struct sockaddr_in server_address1;
	bzero((void*) &server_address1, sizeof(server_address1));
	server_address1.sin_family = AF_INET;
	server_address1.sin_addr.s_addr = INADDR_ANY;
	server_address1.sin_port = htons(this->port_);
	int errno = bind(this->server_socket_1_,
			(struct sockaddr*) &server_address1, sizeof(server_address1));
	if (errno == -1) {
		throw "Error (binding 1)";
		exit(-1);
	}

	//start listening to incoming connections
	listen(this->server_socket_1_, BACK_LOG);

	while(true){
		//define the client socket structures
		struct sockaddr_in client_address;
		socklen_t client_address_len = sizeof(client_address);

		// Connect to a client tries to communicate with the server
		client_socket = accept(this->server_socket_1_,
				(struct sockaddr*) &client_address, &client_address_len);
		//cout << "CLIENT 1 CONNECTED. WAITING FOR CLIENT 2" << endl;
		if (client_socket == -1) {
			throw "Error (accept 1)";
			continue;
		}

		this->handler_.handleClient(client_socket);
		// Todo - something with lst of all the open sokets.
		//close(client_socket);
	}
}

void Server::handleClient(int client_socket1, int client_socket2) {
	int num1, num2;
	int n;
	while (true) {
		//read new arguments from client1
		n = read(client_socket1, &num1, sizeof(num1));
		if (n == -1) {
			throw "Error (reading num1)";
			exit(-1);
		}
		if (n == 0) {
			cout << "Client 1 disconnected" << endl;
			//return;
			continue;
			//check what to do if client 2 disconnects while client 1 is connected
		}
		n = read(client_socket1, &num2, sizeof(num2));
		if (n == -1) {
			throw "Error (reading num2)";
			exit(-1);
		}
		cout << "GOT:" << num1 << " , " << num2 << endl;

		//write numbers to client2
		n = write(client_socket2, &num1, sizeof(num1));
		if (n == -1) {
			throw "Error (writing num1)";
			exit(-1);
		}
		n = write(client_socket2, &num2, sizeof(num2));
		if (n == -1) {
			throw "Error (writing num2)";
			exit(-1);
		}

		//read new arguments from client2
		n = read(client_socket2, &num1, sizeof(num1));
		if (n == -1) {
			throw "Error (reading num1)";
			exit(-1);		}
		if (n == 0) {
			cout << "Client 2 disconnected" << endl;
			return;
		}
		n = read(client_socket2, &num2, sizeof(num2));
		if (n == -1) {
			throw "Error (reading num2)";
			exit(-1);
		}
		cout << "GOT:" << num1 << " , " << num2 << endl;

		//write numbers to client1
		n = write(client_socket1, &num1, sizeof(num1));
		if (n == -1) {
			throw "Error (writing num1)";
			exit(-1);
		}
		n = write(client_socket1, &num2, sizeof(num2));
		if (n == -1) {
			throw "Error (writing num2)";
			exit(-1);
		}
	}
}

void Server::stop() {
	close(this->server_socket_1_);
}

void Server::setConfigs() {
	const char* filename =
			"./config.txt";
	std::ifstream inFile(filename);

	// Make sure the file stream is good
	if (!inFile) {
		cout << endl << "Failed to open file " << filename;
		return;
	}
	int port;
	inFile >> port;
	this->port_ = port;
}
