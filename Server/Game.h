/*
 * Game.h
 *
 *  Created on: Dec 28, 2017
 *      Author: shomps
 */

#ifndef SRC_SERVER_GAME_H_
#define SRC_SERVER_GAME_H_

#include <string>
using namespace std;

typedef struct {
	string name;
	int socket;
} Game;


#endif /* SRC_SERVER_GAME_H_ */
