/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Game.h
 * Description : Defines the Game struct.
 */

#ifndef SRC_SERVER_GAME_H_
#define SRC_SERVER_GAME_H_

#include <string>
using namespace std;

typedef struct {
	string name_;
	int socket_;
} Game;


#endif /* SRC_SERVER_GAME_H_ */
