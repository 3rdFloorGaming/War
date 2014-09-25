/*
  Author:  Garth Murray, Zac Crane, Connor Grumling, Zach Alford
  Course:  COMP 220, Computer Programming II
  Date:    24 September 2014
  Description:  This file gives declarations for the functions of the Player Object.
*/





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



