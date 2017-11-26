/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "GeneralDefinitions.h"
#include "Board.h"
#include <vector>
using namespace std;

/** This class is an interface that represents a reversy player.*/
class Player{
public:
	/** Function name	: move
	 *  Parameters		: The functions gets a list of possible move.
	 *  Return value	: The point chosen between the points provided.
	 *  General flow	: The function let the user chose between the optional points,
	 *  				  checks if the point is from the point provided, and returns the point chosen.
	 */
	virtual Point move(vector<Point *> * moves) = 0;

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: The returns the player value, "color".
	 *  General flow	: The function return the player's value, the player's color.
	 */
	virtual CellValue getValue () const = 0;

	/** Function name	: setBoard
	 *  Parameters		: board - A game board.
	 *  Return value	: None.
	 *  General flow	: The functions set the board the player uses.
	 */
	virtual void setBoard(Board * board) = 0;

	/** Function name	: ~Player
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Distractor of player.
	 */
	virtual ~Player(){};
};

#endif /* PLAYER_H_ */
