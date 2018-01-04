/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Player.h
 * Description : Defines the methods of any player
 * 				 in the game. (Interface)
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "GeneralDefinitions.h"
#include "Board.h"
#include "Point.h"
#include <vector>
using namespace std;

class Player {
public:
	/** Function name	: move
	 *  Parameters      : list of possible moves, last move of  the opponent,
	 *  				  game board.
	 *  Return value	: The point chosen between the points provided.
	 *  General flow	: The function lets the user choose their next move,
	 *  				  checks if the point is legal,
	 *  				  and returns the point finally chosen.
	 */
	virtual Point move(vector<Point *> * moves, Point opponent_move,
			Board &board) = 0;

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: a player's value, their "color".
	 *  General flow	: The function returns the player's value,
	 *  				  the player's color.
	 */
	virtual CellValue getValue() const = 0;

	/** Function name	: ~Player
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Player destructor.
	 */
	virtual ~Player() {
	};
};

#endif /* PLAYER_H_ */
