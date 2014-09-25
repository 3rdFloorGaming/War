/*
  Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
  Course:  COMP 220, Computer Programming II
  Date:    24 September 2014
  Description:  This file gives declarations for the functions of the Player Object.
*/

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

bool Player::winsByWars()
{
	if(warsWon>=WARSTOWIN) return true;
	return false;
}

bool Player::lossByCards()
{
	if(numCards()==0) return true;
}