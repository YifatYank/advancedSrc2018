/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : AIPlayer.h
 * Description : Defines the attributes and methods of an
 * 				 artificial player in the game. (Interface)
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
	 *  Parameters		: Player's value ('color').
	 *  Return value	: The created console player.
	 *  General flow	: Assignment of the members.
	 */
	AIPlayer(CellValue value, GameLogic * logic);

	/** Function name	: move
	 *  Parameters      : list of possible moves, last move of  the opponent,
	 *  				  game board.
	 *  Return value	: The point chosen between the points provided.
	 *  General flow	: The function lets the user choose their next move,
	 *  				  checks if the point is legal,
	 *  				  and returns the point finally chosen.
	 */
	virtual Point move(vector<Point *> * moves, Point last_move, Board &board);

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: a player's value, their "color".
	 *  General flow	: The function returns the player's value,
	 *  				  the player's color.
	 */
	virtual CellValue getValue() const;

	/** Function name	: ~AIPlayer
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: AIPlayer destructor.
	 */
	virtual ~AIPlayer();
};

#endif /* SRC_AIPLAYER_H_ */
