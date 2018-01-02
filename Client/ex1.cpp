/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : main.cpp
 * Description : Calls the methods to run the game.
 */

#include <iostream>
#include "GeneralDefinitions.h"
#include "ClassicLogic.h"
#include "GameLogic.h"
#include "ConsolePlayer.h"
#include "GameManager.h"
#include "ConsuleDisplay.h"
#include "AIPlayer.h"
#include "RemotePlayer.h"
#include "Client.h"
#include "ClientCommandsManager.h"

using namespace std;
/** Function name	: PrintBoard
 *  Parameters		: A game board.
 *  Return value	: None
 *  General flow	: The function prints the game board.
 */
void printBoard(Board &game);

/** Function name	: main
 *  Parameters		: None.
 *  Return value	: None
 *  General flow	: The function creates a new "reversi" game,
 *  				  and prints the board.
 */
int main() {
	Player * first;
	Player * second;
	ConsuleDisplay gui = ConsuleDisplay();

	GameType type = gui.DisplayOpenMenu();
	switch (type) {
	case (TWO_PLAYERS): {
		first = new ConsolePlayer(WHITE);
		second = new ConsolePlayer(BLACK);
		break;
	}
	case (AGAINST_COMPUTER): {
		GameLogic * logic = new ClassicLogic(new Board(4));
		first = new AIPlayer(WHITE, logic);
		second = new ConsolePlayer(BLACK);
		break;
	}
	case (REMOTE_PALYER): {
		Player * temp;
		ClientCommandsManager commander = ClientCommandsManager(
						*(Client::getInctance()), &temp);
		bool started = false;
		string command, name;
		do {
			cin >> command;
			if(command != "list_games"){
				cin >> name;
				command += " ";
				command += name;
			}

			started = commander.ExecuteCommand(command);
		} while (!started);
		//cout << "exited loop" << endl;
		if (temp->getValue() == WHITE) {
			second = temp;
			first = new ConsolePlayer(BLACK);
		} else {
			first = temp;
			second = new ConsolePlayer(WHITE);
		}
		break;
	}
	}

	GameManager * manage = new GameManager(first, second, 4);
	manage->play();

	delete (manage);
	delete (first);
	delete (second);
	return 0;
}

//implementation of the printBoard function from above.
void printBoard(Board &game) {
	int index, jndex;

	cout << " |";
	for (index = 1; index <= game.getGameBoardWidth(); ++index) {
		cout << " " << index << " |";
	}
	cout << endl << "----------------------------------" << endl;

	for (index = 1; index <= game.getGameBoardWidth(); ++index) {
		cout << index << "|";
		for (jndex = 1; jndex <= game.getGameBoardWidth(); ++jndex) {
			switch (game.getCellValue(index, jndex)) {
			case (EMPTY): {
				cout << "   |";
				break;
			}
			case (WHITE): {
				cout << " O |";
				break;
			}
			case (BLACK): {
				cout << " X |";
				break;
			}
			default: {
				break;
			}
			}
		}
		cout << endl << "----------------------------------" << endl;
	}
}
