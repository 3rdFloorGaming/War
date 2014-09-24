

#include "player.h"


Player::Player()
{
	deck.resize(0);
	//discard.resize(0);	Only if we have such a deck
}

Player::Player(vector<Card> deckA)
{
	deck=deckA;
	discard.resize(0);
}

void::Player addCard(Card A)
{
	deck.push_back(A);
	//discard.push_back(A);		We should pick one of these.
}

Card::Player playCard();
{
	Card temp;
	temp=deck[0];
	deck.erase(deck.begin());
	return temp;
}

int::Player numCards();
{
	int temp;
	temp=deck.size();//+discard.size();		Same as above
}