/*
 * AIPlayer.h
 *
 *  Created on: Nov 27, 2017
 *      Author: shomps
 */

#ifndef SRC_AIPLAYER_H_
#define SRC_AIPLAYER_H_

#include "Player.h"
#include "ConsuleDisplay.h"
#include "GameLogic.h"
using namespace std;

class AIPlayer: public Player {
private:
	CellValue value_;
	GameLogic * logic_;

public:
	/** Function name	: AIPlayer
	 *  Parameters		: value - The players value - the player 'color'.
	 *  Return value	: The console player created.
	 *  General flow	: Assignment of the members.
	 */
	AIPlayer(CellValue value, GameLogic * logic);

	/** Function name	: move
	 *  Parameters		: The functions gets a list of possible move, and the last move of  the opponent.
	 *  Return value	: The point chosen between the points provided.
	 *  General flow	: The function let the user chose between the optional points,
	 *  				  checks if the point is from the point provided, and returns the point chosen.
	 */
	virtual Point move(vector<Point *> * moves, Point last_move, Board &board);

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: The returns the player value, "color".
	 *  General flow	: The function return the player's value, the player's color.
	 */
	virtual CellValue getValue () const;

	/** Function name	: ~AIPlayer
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Destructor of AIPlayer.
	 */
	virtual ~AIPlayer();
};



#endif /* SRC_AIPLAYER_H_ */
