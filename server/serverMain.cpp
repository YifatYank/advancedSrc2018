/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ServerMain.cpp
 * Description : functions as the Server's main method
 */

#include "Server.h"
#include "ClientHandler.h"
#include "ThreadManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#define PORT 8002

typedef struct {
	Server * server;
	ThreadManager * threads;
	SocketManager * sockets;
	GameMaster * games;
	pthread_t main_thread_no;
} ParamsToOuterThread;

static void * OuterThread(void * params);

int main() {
	ThreadManager * threads = new ThreadManager();
	SocketManager * sockets = new SocketManager();
	ClientHandler handle = ClientHandler(sockets, threads);
	Server * server = new Server(PORT, handle, sockets, threads);

	pthread_t threadno;
	// Create the thread and send the arguments to it.
	pthread_create(&threadno, NULL, OuterThread, (void *) server);

	// Set the exit thread
	ParamsToOuterThread * params = (ParamsToOuterThread*) malloc(
			sizeof(ParamsToOuterThread));
	params->server = server;
	params->threads = threads;
	params->sockets = sockets;
	params->games = handle.getGameMaster();
	params->main_thread_no = threadno;

	string message;
	do {
		cin >> message;
	} while (message != "exit");

	ParamsToOuterThread * everything = (ParamsToOuterThread*) params;
	everything->threads->killAll();
	delete (everything->games);
	vector<int> waiting = everything->sockets->getWaiting();
	vector<int> playing = everything->sockets->getInGame();
	string destroy = "_red_button_";
	int release = -2;
	int err;
	vector<int>::iterator it;
	for (it = waiting.begin(); it != waiting.end(); it++) {
		err = write(*it, &destroy, destroy.size());
		if (err == -1) {
			throw "Error (destroying client)";
			exit(-1);
		}
	}
	for (it = playing.begin(); it != playing.end(); it++) {
		for (int i = 0; i < 2; i++) {
			err = write(*it, &release, sizeof(release));
			if (err == -1) {
				throw "Error (releasing client)";
				exit(-1);
			}
			err = write(*it, &release, sizeof(release));
			if (err == -1) {
				throw "Error (releasing client)";
				exit(-1);
			}
		}
	}
	everything->sockets->closeAll();
	pthread_cancel(everything->main_thread_no);
	everything->server->stop();
	delete (everything->server);
	free(everything);
	return 0;
}

static void * OuterThread(void * params) {
	Server * server = (Server*) params;
	server->start();
	return NULL;
}
