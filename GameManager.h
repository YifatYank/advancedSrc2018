/*
 * GameManager.h
 *
 *  Created on: Nov 27, 2017
 *      Author: yifat
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Player.h"
#include "GameLogic.h"
#include "GameDisplay.h"

class GameManager {
private:
	Player * white_;
	Player * black_;
	GameLogic * logic_;
	Board * game_board_;
	GameDisplay * display_;
	CellValue winner_;

public:
	GameManager(Player * white, Player * black, int width);
	/** Function name	: playLogic
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Plays the game, until it ends.
	 */
	virtual void play();

	/** Function name	: getWinner
	 *  Parameters		: None.
	 *  Return value	: The game's winner.
	 *  General flow	: Returns the game's winner - if the game has not over yet, the functions returns EMPTY.
	 */
	virtual CellValue getWinner();

	virtual ~GameManager();
};

#endif /* GAMEMANAGER_H_ */
