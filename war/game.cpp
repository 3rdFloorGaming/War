

#include "game.h"
#include "card.h"
#include "card.cpp"
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>

using std::vector;
using std::random_shuffle;
using std::make_move_iterator;

void givePlayersCards( vector <Card> &p1, vector <Card> &p2)
{
	//Creates deck that players will use
	vector<Card> deck;

	//For loop that populates deck
    for (int j=0; j<13; j++) 
	{
        for (int i=0; i<4; i++) 
		{
			deck.push_back(Card(Value(j), Suit(i)));
        }               
    }

	//Random seed used for shuffling deck
	srand(time(0));

	//Shuffles deck
	random_shuffle(deck.begin(), deck.end(), myrandom();

	//Splits deck into two player decks
	vector<Card> player1(make_move_iterator(deck.begin() + deck.size()/2), make_move_iterator(deck.end()));
	//Erases half of original deck that has been given to player 2's deck
	deck.erase(deck.begin() + deck.size()/2, deck.end());
	//Fills player2 deck with remaining cards
	vector<Card> player2(make_move_iterator(deck.begin() + deck.size(), make_move_iterator(deck.end()));
}
void givePlayersCards( vector <Card> &p1, vector <Card> &p2, vector <Card> &p3) //Overloaded to accamodate any number of players
void givePlayersCards( vector <Card> &p1, vector <Card> &p2, vector <Card> &p3, vector <Card> &p4) //Will need to be different code than 
string compareCards(Card p1, Card p2); //Stuff in comments will go in game.cpp

//Comparison test (compares last card in player decks and pops cards after comparison)
string compareCards(Card p1, Card p2)
{
	if(p1.getValue() > p2.getValue())
	{		
		return "p1";
	}
	else if(p1.getValue() < p2.getValue())
	{
		return "p2";
	}
	else
	{
		return "war";
	}
}
