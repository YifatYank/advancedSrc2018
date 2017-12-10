/*
 * Server.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: shomps
 */

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

Server::Server(int port) :
		port_(port), server_socket_1_(0), server_socket_2_(0) {
	cout << "SERVER CONSTRUCTED!" << endl;
}

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
	int errno = bind(this->server_socket_1_, (struct sockaddr*) &server_address1,
			sizeof(server_address1));
	if (errno == -1) {
		cout << "Error (binding 1)" << endl;
		return;
	}
	struct sockaddr_in server_address2;
		bzero((void*) &server_address2, sizeof(server_address2));
		server_address2.sin_family = AF_INET;
		server_address2.sin_addr.s_addr = INADDR_ANY;
		server_address2.sin_port = htons(this->port_);
		int errno = bind(this->server_socket_2_, (struct sockaddr*) &server_address2,
				sizeof(server_address2));
		if (errno == -1) {
			cout << "Error (binding 2)" << endl;
			return;
		}

	while (true) {
		int color = 1;
		//start listening to incoming connections
		listen(this->server_socket_1_, 2);
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

void Server::handleClient(int client_socket1, int client_socket2) {
	int num1, num2;
	while (true) {
		//read new arguments from client1
		int n = read(client_socket1, &num1, sizeof(num1));
		if (n == -1) {
			cout << "Error (reading num1)" << endl;
			return;
		}
		if (n == 0) {
			cout << "Client 1 disconnected" << endl;
			return;
		}
		n = read(client_socket1, &num2, sizeof(num2));
		if (n == -1) {
			cout << "Error (reading num2)" << endl;
			return;
		}
		cout << "GOT:" << num1 << " , " << num2 << endl;

		//write numbers to client2
		n = write(client_socket2, &num1, sizeof(num1));
		if (n == -1) {
			cout << "Error (writing num1)" << endl;
			return;
		}
		n = write(client_socket2, &num2, sizeof(num2));
		if (n == -1) {
			cout << "Error (writing num2)" << endl;
			return;
		}

		//read new arguments from client2
		int n = read(client_socket2, &num1, sizeof(num1));
		if (n == -1) {
			cout << "Error (reading num1)" << endl;
			return;
		}
		if (n == 0) {
			cout << "Client 2 disconnected" << endl;
			return;
		}
		n = read(client_socket2, &num2, sizeof(num2));
		if (n == -1) {
			cout << "Error (reading num2)" << endl;
			return;
		}
		cout << "GOT:" << num1 << " , " << num2 << endl;

		//write numbers to client1
		n = write(client_socket1, &num1, sizeof(num1));
		if (n == -1) {
			cout << "Error (writing num1)" << endl;
			return;
		}
		n = write(client_socket1, &num2, sizeof(num2));
		if (n == -1) {
			cout << "Error (writing num2)" << endl;
			return;
		}
	}
}

int Server::add(int a, int b) {
	return a + b;
}

void Server::stop() {
	close(this->server_socket_1_);
	close(this->server_socket_2_);
}


