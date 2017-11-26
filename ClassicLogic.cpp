/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#include "ClassicLogic.h"
using namespace std;

ClassicLogic::ClassicLogic(int board_size, Player * first, Player * second) : white_(first), black_(second) {
	int half = board_size / 2;
	this->gameBoard_ = new Board(board_size);
	this->gameBoard_->setCellValue(half, half, WHITE);
	this->gameBoard_->setCellValue(half + 1,half + 1, WHITE);
	this->gameBoard_->setCellValue(half,half + 1, BLACK);
	this->gameBoard_->setCellValue(half + 1, half, BLACK);
	this->winner_ = EMPTY;
	this->black_->setBoard(this->gameBoard_);
	this->white_->setBoard(this->gameBoard_);
	this->display = new ConsuleDisplay();
}

ClassicLogic::~ClassicLogic() {
	delete(this->gameBoard_);
	delete(this->display);
}

bool ClassicLogic::playDirection(int x,int y,int xMove,int yMove, CellValue value, bool checkMode) {
    int isTurned;

    // If out of range
    if(this->gameBoard_->getCellValue(x,y) == BOEDER) {
        return false;
    }

    // If we reached an empty spot.
    if(this->gameBoard_->getCellValue(x,y) == EMPTY){
        // 1 means false
    	return false;
    }

    // If we reaches a cell with the current player's color
    if(this->gameBoard_->getCellValue(x,y) == value){
        return true;
    }

    // We are in a cell with the opponent's color
    // Checks if there is a cell with the players color in the end
    isTurned = playDirection(x + xMove, y + yMove, xMove, yMove, value, checkMode);
    // If we have to turn the cell's color
    if(isTurned){
        if(!checkMode) {
            this->gameBoard_->setCellValue(x,y,value);
        }
    }
    return isTurned;
}

bool ClassicLogic::playMove(Point move, CellValue value) {
	bool is_legal = false;

	this->gameBoard_->setCellValue(move.x_,move.y_,value);
	// Change up
	if((this->gameBoard_->getCellValue(move.x_- 1, move.y_) != BOEDER) &&
	   (this->gameBoard_->getCellValue(move.x_ - 1,move.y_) != EMPTY) &&
	   (this->gameBoard_->getCellValue(move.x_ - 1,move.y_) != value) &&
	   (this->playDirection(move.x_ - 1, move.y_, -1,0, value,false))) {
		is_legal = true;
	}

	// Change down
	if((this->gameBoard_->getCellValue(move.x_ + 1,move.y_) != BOEDER) &&
	   (this->gameBoard_->getCellValue(move.x_ + 1,move.y_) != EMPTY) &&
	   (this->gameBoard_->getCellValue(move.x_ + 1,move.y_) != value) &&
	   (this->playDirection(move.x_ + 1, move.y_, 1,0, value,false))) {
		is_legal = true;
	}

	// Check left.
	if ((this->gameBoard_->getCellValue(move.x_,move.y_ - 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.x_,move.y_ - 1) != EMPTY) &&
	    (this->gameBoard_->getCellValue(move.x_,move.y_ - 1) != value) &&
		(this->playDirection(move.x_, move.y_ - 1, 0, - 1, value,false))) {
		is_legal = true;
	}

	// Check right.
	if ((this->gameBoard_->getCellValue(move.x_,move.y_ + 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.x_,move.y_ + 1) != EMPTY) &&
	    (this->gameBoard_->getCellValue(move.x_,move.y_ + 1) != value) &&
	    (this->playDirection(move.x_, move.y_ + 1, 0, 1, value,false))) {
		is_legal = true;
	}

	// Check up right
	if ((this->gameBoard_->getCellValue(move.x_ + 1,move.y_ + 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.x_ + 1,move.y_ + 1) != EMPTY) &&
	    (this->gameBoard_->getCellValue(move.x_ + 1,move.y_+ 1) != value) &&
	    (this->playDirection(move.x_ + 1, move.y_ + 1, 1, 1, value,false))) {
		is_legal = true;
	}

	// Check up left
	if ((this->gameBoard_->getCellValue(move.x_ + 1,move.y_ - 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.x_ + 1,move.y_ - 1) != EMPTY) &&
	    (this->gameBoard_->getCellValue(move.x_ + 1,move.y_ - 1) != value) &&
	    (this->playDirection(move.x_ + 1, move.y_ - 1, 1, - 1, value,false))) {
		is_legal = true;
	}

	// Check down right
	if ((this->gameBoard_->getCellValue(move.x_ - 1,move.y_ + 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.x_ - 1,move.y_ + 1) != EMPTY) &&
	    (this->gameBoard_->getCellValue(move.x_ - 1,move.y_+ 1) != value) &&
	    (this->playDirection(move.x_ - 1, move.y_ + 1, -1,1, value,false))) {
		is_legal = true;
	}

	// Check down left
	if ((this->gameBoard_->getCellValue(move.x_ - 1,move.y_ - 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.x_ - 1,move.y_ - 1) != EMPTY) &&
	    (this->gameBoard_->getCellValue(move.x_ - 1,move.y_ - 1) != value) &&
	    (this->playDirection(move.x_ - 1, move.y_ - 1, -1, -1, value,false))) {
		is_legal = true;
	}
	return is_legal;
}

vector <Point *> * ClassicLogic::getLegalMoves(CellValue value){
    int height = this->gameBoard_->getGameBoardWidth();


    vector<Point *> * moves_list = new vector<Point *>();
    // Goes trough all the array cells and search for a legal move.
    for(int index = 1; index <= height; index++){
    	for(int jndex = 1; jndex <= height; jndex++){
    		if(this->gameBoard_->getCellValue(index, jndex) == EMPTY) {
    			// Check up
    			if((this->gameBoard_->getCellValue(index - 1,jndex) != BOEDER) &&
    			   (this->gameBoard_->getCellValue(index - 1,jndex) != EMPTY) &&
				   (this->gameBoard_->getCellValue(index - 1,jndex) != value) &&
				   (this->playDirection(index - 1, jndex, -1,0, value,true))) {
    				Point * p = new Point();
    				p->x_ = index;
    				p->y_ = jndex;
    				moves_list->push_back(p);
				// Check down
    			} else if((this->gameBoard_->getCellValue(index + 1,jndex) != BOEDER) &&
    					  (this->gameBoard_->getCellValue(index + 1,jndex) != EMPTY) &&
						  (this->gameBoard_->getCellValue(index + 1,jndex) != value) &&
						  (this->playDirection(index + 1, jndex, 1,0, value,true))) {
    				Point * p = new Point();
    				p->x_ = index;
    				p->y_ = jndex;
    				moves_list->push_back(p);
    			// Check left.
    			} else if ((this->gameBoard_->getCellValue(index,jndex - 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index,jndex - 1) != EMPTY) &&
					       (this->gameBoard_->getCellValue(index,jndex - 1) != value) &&
					       (this->playDirection(index, jndex - 1, 0, - 1, value,true))) {
    				Point * p = new Point();
    				p->x_ = index;
    				p->y_ = jndex;
    				moves_list->push_back(p);
    			// Check right.
    			} else if ((this->gameBoard_->getCellValue(index,jndex + 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index,jndex + 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index,jndex + 1) != value) &&
						   (this->playDirection(index, jndex + 1, 0, 1, value,true))) {
    				Point * p = new Point();
    				p->x_ = index;
    				p->y_ = jndex;
    				moves_list->push_back(p);
    				// Check up right
    			} else if ((this->gameBoard_->getCellValue(index + 1,jndex + 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index + 1,jndex + 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index + 1,jndex + 1) != value) &&
						   (this->playDirection(index + 1, jndex + 1, 1, 1, value,true))) {
    				Point * p = new Point();
    				p->x_ = index;
    				p->y_ = jndex;
    				moves_list->push_back(p);
				// 	Check up left
    			} else if ((this->gameBoard_->getCellValue(index + 1,jndex - 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index + 1,jndex - 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index + 1,jndex - 1) != value) &&
						   (this->playDirection(index + 1, jndex - 1, 1, - 1, value,true))) {
    				Point * p = new Point();
    				p->x_ = index;
    				p->y_ = jndex;
    				moves_list->push_back(p);
				// 	Check down right
    			} else if ((this->gameBoard_->getCellValue(index - 1,jndex + 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index - 1,jndex + 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index - 1,jndex + 1) != value) &&
						   (this->playDirection(index - 1, jndex + 1, -1,1, value,true))) {
    				Point * p = new Point();
    				p->x_ = index;
    				p->y_ = jndex;
    				moves_list->push_back(p);
				// 	Check down left
    			} else if ((this->gameBoard_->getCellValue(index - 1,jndex - 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index - 1,jndex - 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index - 1,jndex - 1) != value) &&
						   (this->playDirection(index - 1, jndex - 1, -1, -1, value,true))) {
						Point * p = new Point();
						p->x_ = index;
						p->y_ = jndex;
						moves_list->push_back(p);
    			}
    		}
    	}
    }
    return moves_list;
}

CellValue ClassicLogic::getWinner() {
	return this->winner_;
}

void ClassicLogic::playLogic() {
	bool is_running = true;

	while(is_running) {
		bool is_valid_move = false, has_played;

		// Play white player.
		// Get all the possible moves for the white player.
		vector<Point *> * moves = this->getLegalMoves(this->white_->getValue());

		// If the white player does not have legal moves.
		if(moves->size() == 0) {
			has_played = false;
			if(this->gameBoard_->getEmptyCellsNumber() != 0) {
				this->white_->move(moves);
			}
		} else {
			has_played = true;
			Point p;
			is_valid_move = false;
			while(!is_valid_move) {
				p = this->white_->move(moves);
				is_valid_move = this->playMove(p, this->white_->getValue());

				// If the user has enter an in valid move.
				// Get the list of possible moves, again.
				if(!is_valid_move){
					moves = this->getLegalMoves(this->white_->getValue());
				}
			}
			cout << "O played (" << p.x_ <<"," << p.y_ <<  ")" << endl << endl;
		}

		// Play Black player.
		// Get all the possible moves for the black player.
		moves = this->getLegalMoves(this->black_->getValue());

		// If the black player does not have legal moves.
		if(moves->size() == 0) {
			if(this->gameBoard_->getEmptyCellsNumber() != 0) {
				this->black_->move(moves);
			}
			// If the white player does not have legal moves as well.
			if(!has_played) {
				is_running = false;
			}
		} else {
			is_valid_move = false;
			Point p;
			while(!is_valid_move) {
				p = this->black_->move(moves);
				is_valid_move = this->playMove(p, this->black_->getValue());

				// If the user has enter an in valid move.
				// Get the list of possible moves, again.
				if(!is_valid_move) {
					moves = this->getLegalMoves(this->black_->getValue());
				}
			}
			cout << "X played (" << p.x_ <<"," << p.y_ << ")" << endl << endl;
		}
	}
	this->display->Display(*this->gameBoard_);
	if(this->gameBoard_->getWhiteCellsNumber() > this->gameBoard_->getBlackCellsNumber()) {
		this->winner_ = this->white_->getValue();
		cout << "Player O has won!" << endl;
	} else {
		this->winner_ = this->black_->getValue();
		cout << "Player X has won!" << endl;
	}
}
