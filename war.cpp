// war.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "card.h"
#include "card.cpp"
#include "game.h"
#include "game.cpp"
#include "player.cpp"
#include "player.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{

	//Ints that record players' score
	int p1_score = 0;
	int p2_score = 0;

	//Players Decks
	vector <Card> player1, player2;
	GivePlayersCards(player1, player2);

	//GAME SIMULATION
	while(player1.size() > 0 && player2.size() > 0)
	{
		//Displays the cards that each player plays
		cout << "Player One plays " << player1.back().name() << endl;
		cout << "Player Two plays " << player2.back().name() << endl;
		
		//Compares cards played
		//Once cards are compared, game moves forward accordingly.
		//i.e. If a "1" is returned, player one won. With a "2", player two wins.
		//A "3" signifies a tie, or a war. 
		if((compareCards(player1.back(), player2.back())) == "p1")
		{
			cout << "Player 1 wins!\n";
			player1.pop_back();
			player2.pop_back();
			p1_score++;
		}
		else if((compareCards(player1.back(), player2.back())) == "p2")
		{
			cout << "Player 2 wins!\n";
			player1.pop_back();
			player2.pop_back();
			p2_score++;
		}
		else if((compareCards(player1.back(), player2.back())) == "war")
		{
			cout << "WAR!\n";
			player1.pop_back();
			player2.pop_back();
		}

		//Waits for user to press 'Enter' before continuing to next round
		cin.ignore();

	}


	//Displays final results
	cout << "Player 1: " << p1_score << endl;
	cout << "Player 2: " << p2_score << endl;

	if(p1_score > p2_score)
	{
		cout << "Player 1 wins!" << endl;
	}
	else if(p2_score < p1_score)
	{
		cout << "Player 2 wins!" << endl;
	}
	else if(p1_score == p2_score)
	{
		cout << "It's a tie!!!" << endl;
	}

	return 0;
}



