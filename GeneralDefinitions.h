/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : GeneralDefinitions.h
 * Description : Defines general information that is
 * 				 needed widely across other classes.
 */

#ifndef GENERALDEFINITIONS_H_
#define GENERALDEFINITIONS_H_

/** The enum represents the possible values that a game cell could have.*/
enum CellValue{ BOEDER,
				EMPTY,
				BLACK,
				WHITE };

/** The enum represents the types of game the user can choose from.*/
enum GameType{  TWO_PLAYERS,
				AGAINST_COMPUTER,
				REMOTE_PALYER};
#endif /* GENERALDEFINITIONS_H_ */
