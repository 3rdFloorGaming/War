


#ifndef ___GAME_H
#define ___GAME_H
//string compareCards(Card p1, Card p2); //Compares cards played by each player
//vector<Card> makeDeck(); //Creates deck to use in game
#include <vector>
#include <string>
#include "card.h"
#include "card.cpp"
#include <ctime>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ctime;
using std::vector;
using std::string;


class Game
{
public:
	//Runs war card game simulation
	void playGame();
	//Compares cards played by each player
	string compareCards(Card p1, Card p2);
	//Creates deck to use in game
	void tieGame(vector <Card> & p1deck,vector <Card> & p2deck);
	//Will run through tie game scenario as many times as necessary
	vector<Card> makeDeck();
	int getP1_Score() {return p1_score;}
	int getP2_Score() {return p2_score;}
private:
	int p1_score;
	int p2_score;
};


/*
vector <Card> makeShuffledDeck()
void givePlayersCards( vector &p1, vector &p2) //Function that will take a huge chunk out of main to generate decks for players
void givePlayersCards( vector &p1, vector &p2, vector &p3) //Overloaded to accamodate any number of players
void givePlayersCards( vector &p1, vector &p2, vector &p3, vector &p4) 
string compareCards(Card p1, Card p2);*/
#endif

