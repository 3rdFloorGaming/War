/*
  File: Player.h
  Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
  Course:  COMP 220, Computer Programming II
  Date:    24 September 2014
  Description:  This file provides control oer certain aspects of game rules and win conditions.
*/

#ifndef ___GAMEVARIABLES_H
#define ___GAMEVARIABLES_H

//Allows play with alternate game rules where a player can win by winning a certain number of wars
bool winCondition_winByWars = true;
		//Checks win by war condition
		/*
		if(player1.winsByWars())
		{
		cout << "Player 1 has won "<< WARSTOWIN<< "wars!\n";
		break;
		}
		if(player2.winsByWars())
		{
		cout << "Player 2 has won "<< WARSTOWIN<< "wars!\n";
		break;
		}
		*/

//How many wars are needed to win with above game condition
const int WARSTOWIN = 5; 


#endif
