/*
  File: Player.h
  Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
  Course:  COMP 220, Computer Programming II
  Date:    24 September 2014
  Description:  This file provides the function prototypes for the Player Object.
*/

#ifndef ___PLAYER_H
#define ___PLAYER_H




class Player
{
public:
	Player ();
	Player (vector<Card> deckA);
	int numCards();
	int warsWon;
	int points;
	bool winsByWars();
	bool lossByCards();
	friend bool checkForWinner(Player p1, Player p2);
private:
	vector<Card> deck;
};

#endif
