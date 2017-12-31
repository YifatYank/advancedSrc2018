/*
 * GameManager.h
 *
 *  Created on: Dec 28, 2017
 *      Author: shomps
 */

#ifndef SRC_SERVER_GAMEMASTER_H_
#define SRC_SERVER_GAMEMASTER_H_

#include "Game.h"
#include <vector>
#include <string>

using namespace std;

class GameMaster {
private:
	vector<Game> games_;
	Game findGame(string);
public:
	GameMaster();
	Game startGame(string name, int socket_number);
	Game joinGame(string name);
	void removeGame(string name);
	vector<string> getGames();
	virtual ~GameMaster();
};

#endif /* SRC_SERVER_GAMEMASTER_H_ */
