/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : GameLogic.h
 * Description : Defines the guidelines used within the game. (Interface)
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_

using namespace std;
#include <vector>
#include "Board.h"
#include "Point.h"

class GameLogic {
public:
	/** Function name	: getLegalMoves
	 *  Parameters		: A player's color.
	 *  Return value	: A vector containing all of the legal
	 *  				  moves the player may choose from.
	 *  General flow	: Check all cells in the game board to see
	 *  				  if they count as legal moves.
	 *  			      If a cell answers the criteria,
	 *  			      the function adds the its location to the vector.
	 */
	virtual vector<Point *> * getLegalMoves(CellValue value) = 0;

	/** Function name	: playMove
	 *  Parameters		: The player's color, player's chosen move.
	 *  Return value	: boolean value depending on the move's legality.
	 *  General flow	: Check if the move is legal.
	 *  				  if it is, play the move.
	 */
	virtual bool playMove(Point move, CellValue value) = 0;

	/**
	 * Function name    : getBoard
	 * Parameters       : none
	 * Return value     : the game's board (pointer)
	 * General flow     : returns a pointer to the game's
	 * 	                  current board.
	 */
	virtual Board * getBoard() = 0;

	/**
	 * Function name     : swapBoard
	 * Parameters        : board pointer
	 * Return value      : board pointer
	 * General flow      : replaces the current board with
	 * 					   given one, placing the former
	 * 					   board under a different pointer.
	 */
	virtual Board * swapBoard(Board * board) = 0;

	/** Function name	: ~GameLogic
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: GameLogic destructor.
	 *  				  Frees board's allocated memory.
	 */
	virtual ~GameLogic() {
	}
};

#endif /* GAMELOGIC_H_ */
