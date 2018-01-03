/*
 * SocketManager.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: shomps
 */


#include "SocketManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

SocketManager::SocketManager() {
	this->sockets_ = vector<int>();
}

void SocketManager::addSocket(int socket) {
	pthread_mutex_lock(&this->socket_mutex_);
	this->sockets_.push_back(socket);
	pthread_mutex_unlock(&this->socket_mutex_);
}

void SocketManager::removeSocket(int socket) {
	pthread_mutex_lock(&this->socket_mutex_);
	vector<int>::iterator it;
	for (it = this->sockets_.begin(); it != this->sockets_.end(); it ++) {
		if ((*it) == socket) {
			this->sockets_.erase(it);
			break;
		}
	}
	pthread_mutex_unlock(&this->socket_mutex_);
}

void SocketManager::removeAll() {
	pthread_mutex_lock(&this->socket_mutex_);
	for (unsigned int i = 0; i < this->sockets_.size(); i ++) {
		this->sockets_.pop_back();
	}
	pthread_mutex_unlock(&this->socket_mutex_);
}

void SocketManager::closeSocket(int socket) {
	pthread_mutex_lock(&this->socket_mutex_);
	vector<int>::iterator it;
	for (it = this->sockets_.begin(); it != this->sockets_.end(); it ++) {
		if ((*it) == socket) {
			this->sockets_.erase(it);
			break;
		}
	}
	close(socket);
	pthread_mutex_unlock(&this->socket_mutex_);
}
void SocketManager::closeAll() {
	pthread_mutex_lock(&this->socket_mutex_);
	for (unsigned int i = 0; i < this->sockets_.size(); i ++) {
		int temp = this->sockets_.back();
		this->sockets_.pop_back();
		close(temp);
	}
	pthread_mutex_unlock(&this->socket_mutex_);
}
SocketManager::~SocketManager() {
	this->closeAll();
}
