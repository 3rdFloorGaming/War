/*
  Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
  Course:  COMP 220, Computer Programming II
  Date:    24 September 2014
  Description:  This is where the project executes from.
*/


#include "game.h"

bool checkForWinner(Player p1, Player&p2);

int main()
{
	Game main;
	main.playGame();
	return 0;
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