/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : GameMaster.cpp
 * Description : Implements the methods of GameMaster
 */

#include "GameMaster.h"

using namespace std;

GameMaster::GameMaster() {
	this->games_ = vector<Game>();
}

Game GameMaster::startGame(string name, int socket_number) {
	pthread_mutex_lock(&this->game_mutex_);
	Game find = findGame(name);
	if (find.name_ != "") {
		Game ret = { "", -1, };
		return ret;
	}
	Game game = { name, socket_number, };
	this->games_.push_back(game);
	pthread_mutex_unlock(&this->game_mutex_);
	return game;
}

Game GameMaster::joinGame(string name) {
	Game ret = findGame(name);
	removeGame(name);
	return ret;
}

void GameMaster::removeGame(string name) {
	pthread_mutex_lock(&this->game_mutex_);
	vector<Game>::iterator it;
	bool is_found = false;
	for (it = this->games_.begin(); it != this->games_.end(); it++) {
		if (it->name_ == name) {
			is_found = true;
			break;
		}
	}
	if (is_found) {
		this->games_.erase(it);
	}
	pthread_mutex_unlock(&this->game_mutex_);
}

vector<string> GameMaster::getGames() {
	pthread_mutex_lock(&this->game_mutex_);
	vector<string> names;
	vector<Game>::iterator it;
	for (it = this->games_.begin(); it != this->games_.end(); it++) {
		names.push_back(it->name_);
	}
	names.push_back(" ");
	pthread_mutex_unlock(&this->game_mutex_);
	return names;
}

GameMaster::~GameMaster() {
	pthread_mutex_lock(&this->game_mutex_);
	this->games_.clear();
	pthread_mutex_unlock(&this->game_mutex_);
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
