


#ifndef ___GAME_H
#define ___GAME_H
//string compareCards(Card p1, Card p2); //Compares cards played by each player
//vector<Card> makeDeck(); //Creates deck to use in game
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
	//Runs war card game simulation
	void playGame();
	//Compares cards played by each player
	string compareCards(Card p1, Card p2);
	//Creates deck to use in game
	vector<Card> makeDeck();
};


/*
vector <Card> makeShuffledDeck()
void givePlayersCards( vector &p1, vector &p2) //Function that will take a huge chunk out of main to generate decks for players
void givePlayersCards( vector &p1, vector &p2, vector &p3) //Overloaded to accamodate any number of players
void givePlayersCards( vector &p1, vector &p2, vector &p3, vector &p4) 
string compareCards(Card p1, Card p2);*/
#endif

