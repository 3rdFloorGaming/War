
#ifndef ___PLAYER_H
#define ___PLAYER_H

#include <vector>
#include "card.h"
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
