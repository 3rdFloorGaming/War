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


class Player
{
public:
	Player ();
	Player (vector<Card> deckA);
	int numCards();
private:
	vector<Card> deck;
};

#endif
