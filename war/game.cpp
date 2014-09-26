/*
Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
Course:  COMP 220, Computer Programming II
Date:    24 September 2014
Description:  This file implements the game rules and functions of play for the game of War.
*/

#include "game.h"



//Makes deck
vector<Card> Game::makeDeck()
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

	//Shuffles deck
	random_shuffle(deck.begin(), deck.end());

	return deck;
}

//Function that compares cards played by each player
string Game::compareCards(Card p1, Card p2)
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

//Function that runs game simulation
void Game::playGame()
{
	//Random seed used for shuffling deck
	srand(unsigned (time(0)));

	int p1_score = 0;
	int p2_score = 0;

	//Int that holds total number of points won in a "war" (tie) scenario
	int war_score = 0;

	//Creates deck (note: Original deck will act as player 1's deck)
	vector<Card> deck = makeDeck();

	//Splits deck into two player decks
	vector<Card> player2(make_move_iterator(deck.begin() + deck.size()/2), make_move_iterator(deck.end()));
	//Erases half of original deck that has been given to player 2's deck
	deck.erase(deck.begin() + deck.size()/2, deck.end());

	while(deck.size() > 0 && player2.size() > 0)
	{
		//Displays the cards that each player plays
		cout << "Player One plays " << deck.back().name() << endl;
		cout << "Player Two plays " << player2.back().name() << endl;

		//Compares cards played
		//Once cards are compared, game moves forward accordingly.
		//i.e. If a "1" is returned, player one won. With a "2", player two wins.
		//A "3" signifies a tie, or a war. 
		if((compareCards(deck.back(), player2.back())) == "p1")
		{
			cout << "Player 1 wins!\n";
			//Removes card from player 2 and adds it to player 1's deck
			deck.insert(deck.begin(), 1, player2.back());
			//Inserts player 1's played card back into deck after it has been "won"
			deck.insert(deck.begin(), 1, deck.back());
			deck.pop_back();
			player2.pop_back();

			p1_score++;

			//Diplays size of each players' deck.
			cout << "Player ONE DECK: " << deck.size() << endl;
			cout << "Player TWO DECK: " << player2.size() << endl;
		}
		else if((compareCards(deck.back(), player2.back())) == "p2")
		{
			cout << "Player 2 wins!\n";
			//Removes card from player 1 and adds it to player 2's deck
			player2.insert(player2.begin(), 1, deck.back());
			//Inserts player 2's played card back into deck after it has been "won"
			player2.insert(player2.begin(), 1, player2.back());
			deck.pop_back();
			player2.pop_back();

			p2_score++;

			//Diplays size of each players' deck.
			cout << "Player ONE DECK: " << deck.size() << endl;
			cout << "Player TWO DECK: " << player2.size() << endl;
		}
		else if((compareCards(deck.back(), player2.back())) == "war")
		{
			cout << "WAR!\n";

			//Creates vector to hold cards on table while "War" (tie) is played out
			//The tied cards stay on the table, then each player places a "face down" card
			//on top of those (pop another card from the deck), then places another "face up"
			//card on the stack. If one player then wins, they collect all six cards. If another
			//"war" occurs, more cards are added.
			vector<Card> tableStack;

			tableStack.push_back(deck.back());
			tableStack.push_back(player2.back());

			//Pops first cards played
			deck.pop_back();
			player2.pop_back();

			//Adds 2 to war_score for both cards played
			war_score+=2;

			do{
				//Adds "face down" cards to vector
				tableStack.push_back(deck.back());
				tableStack.push_back(player2.back());

				//Pops face down cards played
				deck.pop_back();
				player2.pop_back();

				war_score++;

				//Adds "face up" cards to vector
				tableStack.push_back(deck.back());
				tableStack.push_back(player2.back());

				//Displays the cards that each player plays
				cout << "Player One plays " << deck.back().name() << endl;
				cout << "Player Two plays " << player2.back().name() << endl;

				//Pops face up cards played
				deck.pop_back();
				player2.pop_back();

				war_score++;

			}while(compareCards(deck.back(), player2.back()) == "war");

			//Again checks who has "won" the round
			if((compareCards(tableStack[tableStack.size()-2], tableStack[tableStack.size()-1])) == "p1")
			{
				cout << "Player 1 wins war!\n";
				//Adds all of the cards used in the war to player 1's deck
				deck.insert(deck.begin(),tableStack.begin(), tableStack.end());
				p1_score += war_score;

			}
			else if((compareCards(tableStack[tableStack.size()-2], tableStack[tableStack.size()-1])) == "p2")
			{
				cout << "Player 2 wins!\n";
				//Adds all of the cards used in the war to player 1's deck
				player2.insert(player2.begin(),tableStack.begin(), tableStack.end());
				p2_score += war_score;
			}

			//Resets war_score to 0, to prepare for next war
			war_score = 0;

			//Empties the tableStack vector and prepares it for next war
			tableStack.clear();

			//Diplays size of each players' deck.
			cout << "Player ONE DECK: " << deck.size() << endl;
			cout << "Player TWO DECK: " << player2.size() << endl;
		}

		//Checks win by war condition
		/*
		if(player1.winsByWars())
		{
		cout << "Player 1 has won "<< WARSTOWIN<< "wars!\n";
		break;
		}
		if(player2.winsByWars())
		{
		cout << "Player 2 has won "<< WARSTOWIN<< "wars!\n";
		break;
		}
		*/

		//Waits for user to press 'Enter' before continuing to next round
		cin.ignore();

	}

	//Displays final results
	cout << "Player 1: " << p1_score << endl;
	cout << "Player 2: " << p2_score << endl;

	if(p1_score > p2_score)
	{
		cout << "Player 1 wins the game!" << endl;
	}
	else if(p2_score < p1_score)
	{
		cout << "Player 2 wins the game!" << endl;
	}
	else if(p1_score == p2_score)
	{
		cout << "It's a tie!!!" << endl;
	}
}



//Functions to allow 2-4 players, incompatible with the rest of code in game.cpp (major reconstruction needed to implement these)

/*
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
*/
