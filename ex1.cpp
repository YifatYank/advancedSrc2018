/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

/**
 * Name        : main.cpp
 * Author      : yifat yankovich
 * Version     : 1.0
 * Description : Board class initialization and simple board
 */
using namespace std;

#include <iostream>
#include "ClassicLogic.h"
#include "GameLogic.h"
#include "ConsolePlayer.h"

/** Function name	: PrintBoard
 *  Parameters		: The functions gets a game board.
 *  Return value	: None
 *  General flow	: The function prints the game board.
 */
void printBoard(Board &game);

/** Function name	: main
 *  Parameters		: None.
 *  Return value	: None
 *  General flow	: The function creates a new reversy game, and prints the board.
 */
int main() {
	Player * white = new ConsolePlayer(WHITE);
	Player * black = new ConsolePlayer(BLACK);
	GameLogic * logic = new ClassicLogic(4,white,black);
	logic->playLogic();

	delete(logic);
	delete(white);
	delete(black);
	return 0;
}


void printBoard(Board &game){
	int index, jndex;

	cout << " |";
	for(index = 1; index <= game.getGameBoardWidth(); ++index) {
		cout << " " << index << " |";
	}
	cout << endl << "----------------------------------" << endl;

	for(index = 1; index <= game.getGameBoardWidth(); ++index) {
		cout << index << "|";
		for(jndex = 1; jndex <=game.getGameBoardWidth(); ++ jndex) {
			switch(game.getCellValue(index, jndex)) {
				case(EMPTY): {
					cout << "   |";
					break;
				} case(WHITE): {
					cout << " O |";
					break;
				} case(BLACK): {
					cout << " X |";
					break;
				} default: {
					break;
				}
			}
		}
		cout << endl << "----------------------------------" << endl;
	}
}
