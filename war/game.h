
#ifndef ___GAME_H;
#define ___GAME_H

#include <vector>
#include "stdafx.h"
#include "game.h"
#include "game.cpp"
#include "card.h"
#include "card.cpp"
#include "player.h"
#include "player.cpp"


vector <Card> makeShuffledDeck()
void givePlayersCards( vector &p1, vector &p2) //Function that will take a huge chunk out of main to generate decks for players
void givePlayersCards( vector &p1, vector &p2, vector &p3) //Overloaded to accamodate any number of players
void givePlayersCards( vector &p1, vector &p2, vector &p3, vector &p4) 
string compareCards(Card p1, Card p2);
#endif

