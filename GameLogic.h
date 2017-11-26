/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

using namespace std;
#include <vector>
#include "Board.h"

/** The class is aninterfase represents the reversy's game logic/ */
class GameLogic{
public:
	/** Function name	: getLegalMoves
	 *  Parameters		: A player's value - a player's color.
	 *  Return value	: A vector contains all the legal moves the player can do.
	 *  General flow	: Check all the cells in the game board - if they are legal moves.
	 *  			      If the cell is a legal move - the function adds the cell's location to the vector.
	 */
	virtual vector<Point *> * getLegalMoves(CellValue value) = 0;

	/** Function name	: playMove
	 *  Parameters		: The player's value - a player's color, and the player's move.
	 *  Return value	: If the move is legal or not.
	 *  General flow	: Check if the move is legal - if  the move is legal the function plays the move.
	 */
	virtual bool playMove(Point move, CellValue value) = 0;

	/** Function name	: getWinner
	 *  Parameters		: None.
	 *  Return value	: The game's winner.
	 *  General flow	: Returns the game's winner - if the game has not over yet, the functions returns EMPTY.
	 */
	virtual CellValue getWinner() = 0;

	/** Function name	: playLogic
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Plays the game, until it ends.
	 */
	virtual void playLogic() = 0;

	/** Function name	: ~GameLogic
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: The classicLogic destractor. Frees the board was allocated in the constractor.
	 */
	virtual ~GameLogic(){}
};

#endif /* GAMELOGIC_H_ */
