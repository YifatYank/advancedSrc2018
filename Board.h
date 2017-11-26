/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "GeneralDefinitions.h"

/**
 * The Board class represents the game board of the game reversy.
 */
class Board{
private:
	CellValue ** game_board_;
	int board_width_;
	int empty_cells_num_;
	int white_cells_num_;
	int black_cells_num_;

public:
	/** Function name	: Board
	 *  Parameters		: The functions gets the board width.
	 *  Return value	: The board that is created.
	 *  General flow	: The function is a constractor of the Board class.
	 *  				  The function creates and initiates the board.
	 *  				  The board's width is the width it have got as a parameter.
	 */
	Board(int width);

	/** Function name	: getCellValue
	 *  Parameters		: The functions gets a board cell coordinates
	 *  Return value	: The value the cell store.
	 *  General flow	: The function returns the cell value it's coordinated was
	 *  				  sent to the function.
	 */
	CellValue getCellValue(int heigth, int width) const;

	/** Function name	: getGameBoardWidth
	 *  Parameters		: None.
	 *  Return value	: The game board's width.
	 *  General flow	: The function returns the game board's width.
	 */
	int getGameBoardWidth()const;

	/** Function name	: ~ Board
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: This is the destractor of the class it frees all
	 *  				  the memory allocated by the class.
	 */
	virtual ~ Board();

	/** Function name	: getEmptyCellsNumber
	 *  Parameters		: None.
	 *  Return value	: The number of empty cells in the board.
	 *  General flow	: The function returns the number of empty cells in the board.
	 */
	int getEmptyCellsNumber()const;

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

	void setCellValue(int x, int y, CellValue value);

};

#endif /* BOARD_H_ */
