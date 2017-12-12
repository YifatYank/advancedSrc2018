/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ConsolePlayer.h
 * Description : Implements the methods of a
 * 				 human player in the game.
 */

#include "ConsolePlayer.h"
#include <iostream>
#include <limits>

ConsolePlayer::ConsolePlayer(CellValue cell_value): value_(cell_value) {
	this->display_ = new ConsuleDisplay();
}

Point ConsolePlayer::move(vector<Point *> * moves, Point opponent_move, Board &board){
	int x_choise, y_choise;
	bool is_valid = false;

	this->display_->Display(board);
	if(opponent_move != Point(-1,-1)) {
		if(this->value_ == WHITE) {
			cout << "X played: (" << opponent_move.getX() <<"," << opponent_move.getY() <<  ")" << endl << endl;
		} else {
			cout << "O played: (" << opponent_move.getX() <<"," << opponent_move.getY() <<  ")" << endl << endl;
		}
	}

	if (this->value_ == WHITE){
		cout << "O: Your turn!" << endl;
	} else {
		cout << "X: Your turn!" << endl;
	}

	if(moves->size() == 0){
		delete(moves);
		cout << "No moves left. Turn passes on!" << endl;
		Point p(-1,-1);
		return p;
	}

	while(!is_valid) {
		cout << "Your possible moves: ";

		vector<Point *>::iterator it = moves->begin();

		cout << "(" << (*it)->getX() << "," << (*it)->getY() << ")";
		it++;
		for(;it!=moves->end(); it++){
			cout << ",(" << (*it)->getX() << "," << (*it)->getY() << ")";
		}
		cout << endl;

		cout << endl << "Please enter your next move (row col):" << endl;
		cin >> x_choise >> y_choise;

		if(!x_choise || !y_choise) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		// Checks if the move the user chose is valid.
		for(it = moves->begin();
				it!=moves->end(); it++) {
			if((*it)->getX() == x_choise && (*it)->getY() == y_choise) {
				is_valid = true;
				break;
			}
		}
		if(!is_valid){
			cout << "Invalid choice, please try again." << endl << endl;
		}
	}

	// free the points vector
	moves->clear();
	delete(moves);

	Point p(0,0);
	p.setX(x_choise);
	p.setY(y_choise);
	return p;
}

ConsolePlayer::~ConsolePlayer() {
	delete(this->display_);
}

CellValue ConsolePlayer::getValue () const{
	return this->value_;
}
