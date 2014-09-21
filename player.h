/*
Please Check through this and see
if there is anything I missed

Z

*/
#ifndef ___PLAYER_H
#define ___PLAYER_H

#include <vector>
#include "card.h"
#include "card.cpp"
using std::vector;




class Player()
{
public:
	Player ();
	Player (vector<Card> deck);
	void addCard(Card);
	Card playCard();
	int numCards();
	//void shuffleDeck();		Same issue as below, otherwise just push_back
private:
	vector<Card>() deck;
	//vector<Card>() discard;	only use this line if we are going
	//							to shuffle the cards that a player wins
};

#endif
