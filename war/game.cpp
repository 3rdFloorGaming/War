/*
Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
Course:  COMP 220, Computer Programming II
Date:    24 September 2014
Description:  This file implements the game rules and functions of play for the game of War.
*/

#include "game.h"



Player::Player()
{
	deck.resize(0);
}

Player::Player(vector<Card> deckA)
{
	deck=deckA;
	
}

int Player::numCards()
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
	return false;
}


bool checkForWinner(Player p1, Player p2)
{
	if(p1.winsByWars())
	{
		cout << "Player 1 has won "<< WARSTOWIN<< "wars!\n";
		cout << "Player 1 wins the game!" << endl;
		return true;
	}
	if(p2.winsByWars())
	{
		cout << "Player 2 has won "<< WARSTOWIN<< "wars!\n";
		cout << "Player 2 wins the game!" << endl;
		return true;
	}
	if(p1.lossByCards())
	{
		cout << "Player 1 has no more cards, Player 2 wins the game!" << endl;
		return true;
	}
	if(p2.lossByCards())
	{
		cout << "Player 2 has no more cards, Player 1 wins the game!" << endl;
		return true;
	}
	return false;
}
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

	Player p1,p2;

	//Creates deck (note: Original deck will act as player 1's deck)
	vector<Card> deck = makeDeck();

	//Splits deck into two player decks
	vector<Card> player2(make_move_iterator(deck.begin() + deck.size()/2), make_move_iterator(deck.end()));
	//Erases half of original deck that has been given to player 2's deck
	deck.erase(deck.begin() + deck.size()/2, deck.end());

	p1=deck;
	p2=player2;

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

			//Diplays size of each players' deck.
			cout << "Player ONE DECK: " << deck.size() << endl;
			cout << "Player TWO DECK: " << player2.size() << endl;
			p1=deck;
			p2=player2;
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


			//Diplays size of each players' deck.
			cout << "Player ONE DECK: " << deck.size() << endl;
			cout << "Player TWO DECK: " << player2.size() << endl;
			p1=deck;
			p2=player2;
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

			do{
				//Adds "face down" cards to vector
				tableStack.push_back(deck.back());
				tableStack.push_back(player2.back());

				//Pops face down cards played
				deck.pop_back();
				player2.pop_back();


				//Adds "face up" cards to vector
				tableStack.push_back(deck.back());
				tableStack.push_back(player2.back());

				//Displays the cards that each player plays
				cout << "Player One plays " << deck.back().name() << endl;
				cout << "Player Two plays " << player2.back().name() << endl;

				//Pops face up cards played
				deck.pop_back();
				player2.pop_back();


			}while(compareCards(deck.back(), player2.back()) == "war");

			//Again checks who has "won" the round
			if((compareCards(deck.back(), player2.back())) == "p1")
			{
				cout << "Player 1 wins war!\n";
				//Adds all of the cards used in the war to player 1's deck
				deck.insert(deck.begin(),tableStack.begin(), tableStack.end());
				p1=deck;
				p2=player2;
			}
			else if((compareCards(deck.back(), player2.back())) == "p2")
			{
				cout << "Player 2 wins!\n";
				//Adds all of the cards used in the war to player 1's deck
				player2.insert(player2.begin(),tableStack.begin(), tableStack.end());
				p1=deck;
				p2=player2;
			}


			//Empties the tableStack vector and prepares it for next war
			tableStack.clear();

			//Diplays size of each players' deck.
			cout << "Player ONE DECK: " << deck.size() << endl;
			cout << "Player TWO DECK: " << player2.size() << endl;
		}



		//Waits for user to press 'Enter' before continuing to next round
		cin.ignore();
		if(checkForWinner(p1,p2)) break;
	}

}






