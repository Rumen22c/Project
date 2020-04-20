
#include "pch.h"
#include <iostream>
#include <string>
#include "chess.h"

using namespace std;

int main()
{
	
	string startGame, playAgain;
	
	cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ ____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  |  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  \\_____|_|  |_|______|_____/_____/ \n" << endl;
	cout << "A game by George Harter" << endl;
	cout << "Enter any key to continue" << endl;
	cin >> startGame;;
	Board board;
	bool newgame = true;
	while (newgame) {
		board.setBoard();
		while (board.playGame());
		cout << "Do you want to play again? (y for yes, anything else for no) ";
		cin >> playAgain;
		if (playAgain != "y")
			newgame = false;
	}


	return 0;
}