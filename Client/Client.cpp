/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Client.cpp
 * Description : Implements the methods of the Client class.
 */

#include "Client.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

using namespace std;

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8000

Client *Client::instance = 0;

Client * Client::getInctance() {
	if (instance == 0) {
		*instance = Client();
	}
	return instance;
}

void Client::ResetInstace() {
	if (instance != 0) {
		delete (instance);
		instance = 0;
	}
}

Client::Client() :
		server_ip_(SERVER_IP), server_port_(SERVER_PORT), client_socket_(0) {
	setConfigs();
	cout << "Client constructed" << endl;
}

Client::Client(const char *server_ip, int server_port) :
		server_port_(server_port), client_socket_(0) {
	strcpy(this->server_ip_, server_ip);
	cout << "Client constructed" << endl;
}

void Client::connectToServer() {
	//create socket point
	this->client_socket_ = socket(AF_INET, SOCK_STREAM, 0);
	if (this->client_socket_ == -1) {
		throw "Error (opening socket)";
	}
	//convert ip string to network address
	struct in_addr address;
	if (!inet_aton(this->server_ip_, &address)) {
		throw "Error (parsing IP address)";
	}
	//get hostent structure for given host address
	struct hostent *server;
	server = gethostbyaddr((const void*) &address, sizeof(address), AF_INET);
	if (server == NULL) {
		throw "HOST IS UNREACHABLE";
	}

	//create structure for server address
	struct sockaddr_in server_address;
	bzero((char*) &address, sizeof(address));

	server_address.sin_family = AF_INET;
	memcpy((char*) &server_address.sin_addr.s_addr, (char*) server->h_addr, server->h_length);
	//htons converts values between  host and network byte order
	server_address.sin_port = htons(this->server_port_);

	//establish connection with TCP server
	if (connect(this->client_socket_, (struct sockaddr*) &server_address,
			sizeof(server_address)) == -1) {
		throw "Error (connecting to server)";
	}
//	cout << "Connected to server" << endl;
//    cout << "Waiting for other player to join..." << endl;
}

void Client::sendInt(int num) {
	//write argument to socket
	int err = write(this->client_socket_, &num, sizeof(num));
	if (err == -1) {
		throw "Error (writing a to socket)";
	}
}

int Client::reciveInt() {
	int num, err;
	err = read(this->client_socket_, &num, sizeof(num));
	if (err == -1) {
		throw "Error (reading result from socket)";
	}
	return num;
}

void Client::disconnectFromServer() {
	if (close(this->client_socket_) == -1) {
		throw "Error (disconnecting from server)";
	}
}

void Client::setConfigs() {
	const char filename[20] = "./config.txt";
	ifstream inFile(filename);

	// Make sure the file stream is good
	if (!inFile) {
		cout << endl << "Failed to open file " << filename;
		return;
	}

	int port;
	char ip[20];
	inFile >> port >> ip;
	this->server_port_ = port;
	strcpy(this->server_ip_, ip);
}

void Client::sendString(string str) {
	const char * str_to_send = str.c_str();
	//write argument to socket
	int err = write(this->client_socket_, &str_to_send, sizeof(str_to_send));
	if (err == -1) {
		throw "Error (writing a to socket)";
	}
}

string Client::reciveString() {
	int err;
	char buffer[BUFFER_SIZE];
	err = read(this->client_socket_, buffer, BUFFER_SIZE);
	if (err == -1) {
		throw "Error (reading result from socket)";
	}
	string str = string(buffer);
	return buffer;
}

