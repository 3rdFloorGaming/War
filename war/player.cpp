

#include "player.h"



Player::Player()
{
	deck.resize(0);
}

Player::Player(vector<Card> deckA)
{
	deck=deckA;
	
}

int Player:: numCards()
{
	return deck.size();
}