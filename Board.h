/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Board.h
 * Description : Defines the attributes and methods
 * 				 used to manage a game board.
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "GeneralDefinitions.h"

class Board {
private:
	CellValue ** game_board_;
	int board_width_;
	int empty_cells_num_;
	int white_cells_num_;
	int black_cells_num_;

public:
	/** Function name	: Board
	 *  Parameters		: board width (integer).
	 *  Return value	: The created board.
	 *  General flow	: Board constructor.
	 *  				  Creates and initializes the board.
	 */
	Board(int width);

	/**
	 * Function name    : Board (copy constructor)
	 * Parameters       : other Board
	 * Return value     : a Board copied from existing Board.
	 */
	Board(Board & obj);

	/** Function name	: getCellValue
	 *  Parameters		: cell coordinates
	 *  Return value	: cell's inner value.
	 *  General flow	: returns the cell's value -
	 *  				  either a color, 'border' or 'empty'.
	 */
	CellValue getCellValue(int heigth, int width) const;

	/** Function name	: getGameBoardWidth
	 *  Parameters		: None.
	 *  Return value	: The game board's width.
	 *  General flow	: The function returns the game board's width.
	 */
	int getGameBoardWidth() const;

	/** Function name	: ~ Board
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Board destructor. Frees board's allocated memory.
	 */
	virtual ~ Board();

	/** Function name	: getEmptyCellsNumber
	 *  Parameters		: None.
	 *  Return value	: The number of empty cells in the board.
	 *  General flow	: The function returns the number of empty cells in the board.
	 */
	int getEmptyCellsNumber() const;

	/** Function name	: getBlackCellsNumber
	 *  Parameters		: None.
	 *  Return value	: The number of black cells in the board.
	 *  General flow	: The function returns the number of black cells in the board.
	 */
	int getBlackCellsNumber() const;

	/** Function name	: getWhiteCellsNumber
	 *  Parameters		: None.
	 *  Return value	: The number of white cells in the board.
	 *  General flow	: The function returns the number of white cells in the board.
	 */
	int getWhiteCellsNumber() const;

	/**
	 * Function name    : setCellValue
	 * Parameters       : two coordinates and a color value
	 * Return value     : none
	 * General flow     : sets given value in cell of given coordinates.
	 */
	void setCellValue(int x, int y, CellValue value);

	/**
	 * Function name    : copyBoard
	 * Parameters       : none
	 * Return value     : Board pointer
	 * General flow     : calls the Board copy constructor.
	 */
	Board * copyBoard();

};

#endif /* BOARD_H_ */
