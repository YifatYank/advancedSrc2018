/*
 * SocketManager.h
 *
 *  Created on: Jan 3, 2018
 *      Author: shomps
 */

#ifndef SRC_SERVER_SOCKETMANAGER_H_
#define SRC_SERVER_SOCKETMANAGER_H_

#include <sys/socket.h>
#include <vector>
#include <pthread.h>

using namespace std;

class SocketManager {
private:
	vector<int> sockets_;
	vector<int> sockets_in_game_;
	pthread_mutex_t socket_mutex_;
public:
	SocketManager();
	void addSocket(int socket);
	void addToGame(int socket);
	vector<int> getInGame();
	vector<int> getWaiting();
	void removeSocket(int socket);
	void removeAll();
	void closeSocket(int socket);
	void closeAll();
	virtual ~SocketManager();
};

#endif /* SRC_SERVER_SOCKETMANAGER_H_ */
