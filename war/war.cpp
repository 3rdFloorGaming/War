// War.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include "Card.cpp"
#include "Card.h"
#include "game.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::random_shuffle;
using std::make_move_iterator;

int main()
{
	playGame();
	return 0;
}
	
