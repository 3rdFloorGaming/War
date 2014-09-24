

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

vector <Card> makeShuffledDeck()//This function returns a vector of a shuffled deck. Every time it is called it will return a different deck.
{
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
	srand (time(NULL));
	int myrandom = rand() % 1000000;  

	//Shuffles deck
	random_shuffle(deck.begin(), deck.end(), myrandom);

	return deck;
}

void givePlayersCards( vector <Card> &p1, vector <Card> &p2) //
{

	vector <Card> deck = makeShuffledDeck();
	int numPlayers = 2;

	//Splits deck into two player decks
	vector<Card> player1(make_move_iterator(deck.begin() + deck.size()/numPlayers), make_move_iterator(deck.end()));
	//Erases half of original deck that has been given to player 1's deck
	deck.erase(deck.begin() + deck.size()/numPlayers, deck.end());
	//Fills player2 deck with remaining cards
	vector<Card> player2(make_move_iterator(deck.begin() + deck.size()), make_move_iterator(deck.end()));
	//Assign and change the player decks
	p1=player1;
	p2=player2;
}
void givePlayersCards( vector <Card> &p1, vector <Card> &p2, vector <Card> &p3) //Overloaded to accamodate any 2-4 players
{
	vector <Card> deck = makeShuffledDeck();
	int numPlayers = 3;

	vector<Card> player1(make_move_iterator(deck.begin() + deck.size()/numPlayers), make_move_iterator(deck.end()));
	deck.erase(deck.begin() + deck.size()/numPlayers, deck.end());
	vector<Card> player2(make_move_iterator(deck.begin() + deck.size()/numPlayers), make_move_iterator(deck.end()));
	deck.erase(deck.begin() + deck.size()/numPlayers, deck.end());
	vector<Card> player3(make_move_iterator(deck.begin() + deck.size()), make_move_iterator(deck.end()));
	p1=player1;
	p2=player2;
	p3=player3;
}
void givePlayersCards( vector <Card> &p1, vector <Card> &p2, vector <Card> &p3, vector <Card> &p4)
{

	vector <Card> deck = makeShuffledDeck();
	int numPlayers = 4;

	vector<Card> player1(make_move_iterator(deck.begin() + deck.size()/numPlayers), make_move_iterator(deck.end()));
	deck.erase(deck.begin() + deck.size()/numPlayers, deck.end());
	vector<Card> player2(make_move_iterator(deck.begin() + deck.size()/numPlayers), make_move_iterator(deck.end()));
	deck.erase(deck.begin() + deck.size()/numPlayers, deck.end());
	vector<Card> player3(make_move_iterator(deck.begin() + deck.size()/numPlayers), make_move_iterator(deck.end()));
	deck.erase(deck.begin() + deck.size()/numPlayers, deck.end());
	vector<Card> player4(make_move_iterator(deck.begin() + deck.size()), make_move_iterator(deck.end()));
	p1=player1;
	p2=player2;
	p3=player3;
	p4=player4;
}

string compareCards(Card p1, Card p2)//Comparison test (compares last card in player decks and pops cards after comparison)
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
