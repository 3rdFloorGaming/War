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
#include "gamevariables.h"

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
};


//Functions to allow 2-4 players, incompatible with the rest of code in game.cpp (major reconstruction needed to implement these)
/*
vector <Card> makeShuffledDeck()
void givePlayersCards( vector &p1, vector &p2) //Function that will take a huge chunk out of main to generate decks for players
void givePlayersCards( vector &p1, vector &p2, vector &p3) //Overloaded to accamodate any number of players
void givePlayersCards( vector &p1, vector &p2, vector &p3, vector &p4) 
*/

#endif

