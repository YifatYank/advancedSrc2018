/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Board.cpp
 * Description : Implements the methods used to manage a
 * 				 game board.
 */

#include "Board.h"

Board::Board(int width){
	// Add the borders
	this->board_width_ = width + 2;

	// Creates the board
	this->game_board_ = new CellValue * [this->board_width_];

	for(int i = 0; i < this->board_width_; ++i) {
		this->game_board_[i] = new CellValue[this->board_width_];
	}

	// Initiate the board
	for(int i = 0; i < this->board_width_; ++i){
		for(int j =0; j < this->board_width_; ++j){
			// If the is a border cell
			if ((i == 0) || (j == 0)
					 || (i == this->board_width_- 1)
					 || (j == this->board_width_ - 1)) {
				this->game_board_[i][j] = BOEDER;
			} else {
				this->game_board_[i][j] = EMPTY;
			}
		}
	}

	this->black_cells_num_ = 0;
	this->white_cells_num_ = 0;
	this->empty_cells_num_ = (this->board_width_ - 2) * (this->board_width_- 2);
}

Board::Board(Board & obj) {
	this->board_width_ = obj.board_width_;
	this->empty_cells_num_ = obj.empty_cells_num_;
	this->white_cells_num_ = obj.white_cells_num_;
	this->black_cells_num_ = obj.black_cells_num_;

	this->game_board_ = new CellValue * [this->board_width_];

	for(int i = 0; i < this->board_width_; ++i) {
		this->game_board_[i] = new CellValue[this->board_width_];
	}

	for(int i = 0; i < this->board_width_; i++) {
		for (int j = 0; j < this->board_width_; j++) {
			this->game_board_[i][j] = obj.getCellValue(i,j);
		}
	}
}

CellValue Board::getCellValue(int heigth, int width) const {
	return this->game_board_[heigth][width];
}

int Board::getBlackCellsNumber() const {
	return this->black_cells_num_ ;
}

int Board::getWhiteCellsNumber() const {
	return this->white_cells_num_;
}

int Board::getEmptyCellsNumber() const{
	return this->empty_cells_num_;
}

Board::~Board() {
	for(int i = 0; i < this->board_width_; ++ i) {
		delete [] this->game_board_[i];
	}
	delete [] this->game_board_;
}

int Board::getGameBoardWidth()const{
	return this->board_width_ - 2;
}

void Board::setCellValue(int x, int y, CellValue value) {
	if(this->game_board_[x][y] == WHITE) {
		this->white_cells_num_--;
		this->empty_cells_num_++;
	} else if(this->game_board_[x][y] == BLACK) {
		this->black_cells_num_ --;
		this->empty_cells_num_++;
	}

	if(value == WHITE) {
		this->game_board_[x][y] = WHITE;
		this->white_cells_num_++;
		this->empty_cells_num_--;
	} else if(value == BLACK){
		this->game_board_[x][y] = BLACK;
		this->black_cells_num_++;
		this->empty_cells_num_--;
	}

}

Board * Board::copyBoard() {
	Board * board = new Board(*this);
	return board;
}

