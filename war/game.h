/*
  Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
  Course:  COMP 220, Computer Programming II
  Date:    24 September 2014
  Description:  This file provides the function prototypes for the Game Object.
*/

#ifndef ___GAME_H
#define ___GAME_H

#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <algorithm> 
#include <cstdlib>
#include <iterator>
#include "card.h"
#include "player.h"


using std::cout;
using std::cin;
using std::endl;
using std::ctime;
using std::vector;
using std::string;
using std::random_shuffle;
using std::make_move_iterator;



class Game
{
public:
	//Creates deck to use in game
	vector<Card> makeDeck();
	//Compares cards played by each player
	string compareCards(Card p1, Card p2);
	//Runs war card game simulation
	void playGame();

	//A function that is part of play game that will check if either player has satisfied win conitions
	bool checkForWinner(Player p1, Player p2);
};



#endif

