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

Server::Server() :
		port_(PORT), server_socket_1_(0) {
	setConfigs();
	cout << "SERVER CONSTRUCTED!" << endl;
}

Server::Server(int port) :
		port_(port), server_socket_1_(0) {
	setConfigs();
	cout << "SERVER CONSTRUCTED!" << endl;
}
/*
 void Server::start() {
 this->server_socket_1_ = socket(AF_INET, SOCK_STREAM, 0);
 if (server_socket_1_ == -1) {
 cout << "Error (opening socket)" << endl;
 return;
 }
 this->server_socket_2_ = socket(AF_INET, SOCK_STREAM, 0);
 if (server_socket_2_ == -1) {
 cout << "Error (opening socket)" << endl;
 return;
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
 cout << "Error (binding 1)" << endl;
 return;
 }
 struct sockaddr_in server_address2;
 bzero((void*) &server_address2, sizeof(server_address2));
 server_address2.sin_family = AF_INET;
 server_address2.sin_addr.s_addr = INADDR_ANY;
 server_address2.sin_port = htons(this->port_);
 errno = bind(this->server_socket_2_, (struct sockaddr*) &server_address2,
 sizeof(server_address2));
 if (errno == -1) {
 cout << "Error (binding 2)" << endl;
 return;
 }

 while (true) {
 int color = 1;
 //start listening to incoming connections
 listen(this->server_socket_1_, NUMBER_OF_CLIENTS);
 //define the client socket structure
 struct sockaddr_in client_address1;
 socklen_t client_address_len1;
 cout << "WAITING FOR CLIENT CONNECTION" << endl;
 //accept new client connection
 int client_socket1 = accept(this->server_socket_1_,
 (struct sockaddr*) &client_address1, &client_address_len1);
 cout << "CLIENT 1 CONNECTED. WAITING FOR CLIENT 2" << endl;
 if (client_socket1 == -1) {
 cout << "Error (accept 1)" << endl;
 return;
 }
 int n = write(client_socket1, &color, sizeof(color));
 if (n == -1) {
 cout << "Error (writing color 1)" << endl;
 return;
 }
 color = 0;
 //start listening to incoming connections
 listen(this->server_socket_2_, 2);
 //define the client socket structure
 struct sockaddr_in client_address2;
 socklen_t client_address_len2;
 cout << "WAITING FOR CLIENT CONNECTION" << endl;
 //accept new client connection
 int client_socket2 = accept(this->server_socket_2_,
 (struct sockaddr*) &client_address2, &client_address_len2);
 cout << "CLIENT 2 CONNECTED." << endl;
 if (client_socket2 == -1) {
 cout << "Error (accept 2)" << endl;
 return;
 }
 n = write(client_socket2, &color, sizeof(color));
 if (n == -1) {
 cout << "Error (writing color 0)" << endl;
 return;
 }
 this->handleClient(client_socket1, client_socket2);
 //close communication with client
 close(client_socket1);
 close(client_socket2);
 }
 }
 */

void Server::start() {
	int client_socket1, client_socket2;

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

	//define the client socket structures
	struct sockaddr_in client_address1;
	socklen_t client_address_len1 = sizeof(client_address1);
	struct sockaddr_in client_address2;
	socklen_t client_address_len2 = sizeof(client_address2);

	while (true) {
		cout << "WAITING FOR CLIENT CONNECTION" << endl;

		//accept new client connection
		client_socket1 = accept(this->server_socket_1_,
				(struct sockaddr*) &client_address1, &client_address_len1);
		cout << "CLIENT 1 CONNECTED. WAITING FOR CLIENT 2" << endl;
		if (client_socket1 == -1) {
			throw "Error (accept 1)";
			exit(-1);
		}

		cout << "WAITING FOR CLIENT CONNECTION" << endl;
		//accept new client connection
		client_socket2 = accept(this->server_socket_1_,
				(struct sockaddr*) &client_address2, &client_address_len2);
		if (client_socket2 == -1) {
			throw "Error (accept 2)";
			exit(-1);
		}
		cout << "CLIENT 2 CONNECTED." << endl;

		cout << "here" << endl;
		// After both of the clients has connected to the server,
		// sending to each player his number.
		int color = 1;
		int n = write(client_socket1, &color, sizeof(color));
		if (n == -1) {
			throw "Error (writing color 1)";
			exit(-1);
		}
		color = 2;

		n = write(client_socket2, &color, sizeof(color));
		if (n == -1) {
			throw "Error (writing color 0)";
			exit(-1);
		}

		// Handle the game between the two clients.
		this->handleClient(client_socket1, client_socket2);
		//close communication with client
		close(client_socket1);
		close(client_socket2);
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
			exit(-1);
		}
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

int Server::add(int a, int b) {
	return a + b;
}

void Server::stop() {
	close(this->server_socket_1_);
}

void Server::setConfigs() {
	const char* filename =
			"Advaned/src/Server/config.txt";
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
