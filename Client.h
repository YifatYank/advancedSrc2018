/*
 * Client.h
 *
 *  Created on: Dec 5, 2017
 *      Author: shomps
 */

#ifndef CLIENT_H_
#define CLIENT_H_

class Client {
private:
	const char *server_ip_;
	int server_port_;
	int client_socket_;
public:
	Client();
	Client(const char *server_ip, int server_port);
	void connectToServer();
	void disconnectFromServer();
	void sendInt(int num);
	int reciveInt();
};


#endif /* CLIENT_H_ */
