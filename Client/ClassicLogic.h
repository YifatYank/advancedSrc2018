/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClassicLogic.h
 * Description : Defines the guidelines used within the
 * 				 classic Othello game.
 */

#ifndef CLASSICLOGIC_H_
#define CLASSICLOGIC_H_
#include "GameLogic.h"
#include "Player.h"
#include "GameDisplay.h"
#include "ConsuleDisplay.h"
#include "Point.h"
#include <iostream>
using namespace std;

class ClassicLogic: public GameLogic {
private:
	Board * game_board_;

	/**
	 * Function name    : playDirection.
	 * Parameters       : two start coordinates, two new x,y values,
	 * 					  player's color, boolean flag
	 * Return value     : boolean flag
	 * General flow     : determines the direction of advance
	 * 					  and checks if there are any tiles to flip
	 * 					  in that direction. Returns answer as boolean flag.
	 */
	bool playDirection(int x, int y, int xMove, int yMove, CellValue value,
			bool checkMode);
public:
	/** Function name	: ClassicLogic
	 *  Parameters		: board pointer.
	 *  Return value	: The created ClassicLogic.
	 *  General flow	: Initializes a ClassLogic with a game board .
	 */
	ClassicLogic(Board * board);

	/**
	 * Function name    : getBoard
	 * Parameters       : none
	 * Return value     : the game's board (pointer)
	 * General flow     : returns a pointer to the game's
	 * 	                  current board.
	 */
	virtual Board * getBoard();

	/**
	 * Function name     : swapBoard
	 * Parameters        : board pointer
	 * Return value      : board pointer
	 * General flow      : replaces the current board with
	 * 					   given one, placing the former
	 * 					   board under a different pointer.
	 */
	virtual Board * swapBoard(Board * board);

	/** Function name	: getLegalMoves
	 *  Parameters		: A player's color.
	 *  Return value	: A vector containing all of the legal
	 *  				  moves the player may choose from.
	 *  General flow	: Check all cells in the game board to see
	 *  				  if they count as legal moves.
	 *  			      If a cell answers the criteria,
	 *  			      the function adds the its location to the vector.
	 */
	virtual vector<Point *> * getLegalMoves(CellValue value);

	/** Function name	: playMove
	 *  Parameters		: The player's color, player's chosen move.
	 *  Return value	: boolean value depending on the move's legality.
	 *  General flow	: Check if the move is legal.
	 *  				  if it is, play the move.
	 */
	virtual bool playMove(Point move, CellValue value);

	/** Function name	: ~ClassicLogic
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: classicLogic destructor.
	 *  				  Frees board's allocated memory.
	 */
	virtual ~ClassicLogic();
};

#endif /* CLASSICLOGIC_H_ */
