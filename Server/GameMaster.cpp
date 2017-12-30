/*
 * GameManager.cpp
 *
 *  Created on: Dec 28, 2017
 *      Author: shomps
 */

#include "GameMaster.h"

using namespace std;

GameMaster::GameMaster() {
	this->games_ = vector<Game>();
}

Game GameMaster::startGame(string name, int socket_number) {
	Game find = findGame(name);
	if (find.name_ != "") {
		Game ret = { "", -1, };
		return ret;
	}
	Game game = { name, socket_number, };
	this->games_.push_back(game);
	return game;
}

Game GameMaster::joinGame(string name) {
	Game ret = findGame(name);
	removeGame(name);
	return ret;
}

void GameMaster::removeGame(string name) {
	vector<Game>::iterator it;
	for (it = this->games_.begin(); it != this->games_.end(); it++) {
		if (it->name_ == name) {
			this->games_.erase(it);
		}
	}
}

GameMaster::~GameMaster() {
	/*
	 vector<Game>::iterator it;
	 for (it = this->games.begin(); it != this->games.end(); it++) {
	 this->games.erase(it);
	 }
	 */
	this->games_.clear();
}

Game GameMaster::findGame(string game) {
	vector<Game>::iterator it;
	for (it = this->games_.begin(); it != this->games_.end(); it++) {
		if (it->name_ == game) {
			Game ret = { it->name_, it->socket_, };
			return ret;
			//return this->games(it - games.begin());
		}
	}
	Game ret = { "" - 1, };
	return ret;
}
