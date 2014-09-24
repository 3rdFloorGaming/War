/*
  File: game.h
  Author(s):  Garth Murray, Connor Grumling, Zatch Alford, Zac Crane
  Course:  COMP 220, Computer Programming II
  Date:    21 September 2014
  Description:  This file provides the definitions of needed functions
				for the core War Card Game.
*/

#ifndef ___GAME_H
#define ___GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include "Card.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::random_shuffle;
using std::make_move_iterator;



string compareCards(Card p1, Card p2); //Compares cards played by each player
void playGame(); //Runs game simulation

vector<Card> makeDeck(); //Creates deck to use in game

/*
vector <Card> makeShuffledDeck()
void givePlayersCards( vector &p1, vector &p2) //Function that will take a huge chunk out of main to generate decks for players
void givePlayersCards( vector &p1, vector &p2, vector &p3) //Overloaded to accamodate any number of players
void givePlayersCards( vector &p1, vector &p2, vector &p3, vector &p4) 
string compareCards(Card p1, Card p2);*/
#endif

