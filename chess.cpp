#include "pch.h"
#include "chess.h"
using namespace std;

Square::Square()
{
	figure = EMPTY;
	color = NONE;
	positionOnTheTable;
}

void Square::setSpace(Square* space)
{
	color = space->getColor();
	figure = space->getFigure();
}

void Square::setEmpty()
{
	color = NONE;
	figure = EMPTY;
}

Figure Square::getFigure()
{
	return figure;
}

Color Square::getColor()
{
	return color;
}

void Square::setFigureAndColor(Figure p, Color c)
{
	figure = p;
	color = c;

}

void printFigures(Figure p, Color c) {
	switch (p)
	{
	case KING: (c == WHITE) ? cout << " K " : cout << " k ";
		break;
	case QUEEN: (c == WHITE) ? cout << " Q " : cout << " q ";
		break;
	case BISHOP:(c == WHITE) ? cout << " B " : cout << " b ";
		break;
	case KNIGHT:(c == WHITE) ? cout << " H " : cout << " h ";
		break;
	case ROOK: (c == WHITE) ? cout << " R " : cout << " r ";
		break;
	case PAWN: (c == WHITE) ? cout << " P " : cout << " p ";
		break;
	case EMPTY: cout << " " << "\21" << " ";
		break;
	default: cout << "XXX";
		break;
	}

}
void Board::printBoard() {

	cout << "   y: 0  1  2  3  4  5  6  7 " << endl << "x:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
		{
			Figure nameofFigure = square[i][j].getFigure();
			Color nameofColour = square[i][j].getColor();
			printFigures(nameofFigure, nameofColour);
			
		}
		cout << endl;
	}

}

bool Board::doMove() {
	
	string move;
	int x1, x2, y1, y2;
	bool stop = false;
	Position startPosition;
	Position endPosition;
	while (!stop)
	{
		(turn == WHITE) ? cout << "White's turn" << endl : cout << "Black's turn" << endl;
		cout << "Type in your move as a single four character string. Use x-coordinates first in each pair." << endl;
		cin >> move;
		x1 = move[0] - 48;
		y1 = move[1] - 48;
		startPosition.setCoordinateX(x1);
		startPosition.setCoordinateY(y1);
		x2 = move[2] - 48;
		y2 = move[3] - 48;
		endPosition.setCoordinateX(x2);
		endPosition.setCoordinateY(y2);
		if (getSquare(startPosition)->getColor() == turn)
		{


			if (makeMove(startPosition,endPosition) == false)
			{
				cout << "Invalid move, try again." << endl;
			}
			else
				stop = true;
		}
		else
			cout << "That's not your piece. Try again." << endl;
	}
	if (getSquare(endPosition)->getFigure() == KING)
		if (getSquare(startPosition)->getColor() == WHITE)
		{
			cout << "WHITE WINS" << endl;
			return false;
		}
		else

		{
			cout << "BLACK WINS" << endl;
			return false;
		}


	if (turn == BLACK)
		turn = WHITE;
	else
		turn = BLACK;

	return true;

}

void Board::setBoard()
{
	square[0][0].setFigureAndColor(ROOK, WHITE);
	square[1][0].setFigureAndColor(KNIGHT, WHITE);
	square[2][0].setFigureAndColor(BISHOP, WHITE);
	square[3][0].setFigureAndColor(QUEEN, WHITE);
	square[4][0].setFigureAndColor(KING, WHITE);
	square[5][0].setFigureAndColor(BISHOP, WHITE);
	square[6][0].setFigureAndColor(KNIGHT, WHITE);
	square[7][0].setFigureAndColor(ROOK, WHITE);

	square[0][7].setFigureAndColor(ROOK, BLACK);
	square[1][7].setFigureAndColor(KNIGHT, BLACK);
	square[2][7].setFigureAndColor(BISHOP, BLACK);
	square[3][7].setFigureAndColor(QUEEN, BLACK);
	square[4][7].setFigureAndColor(KING, BLACK);
	square[5][7].setFigureAndColor(BISHOP, BLACK);
	square[6][7].setFigureAndColor(KNIGHT, BLACK);
	square[7][7].setFigureAndColor(ROOK, BLACK);

	for (int i = 0; i < 8; i++)
	{
		square[i][1].setFigureAndColor(PAWN, WHITE);
		square[i][6].setFigureAndColor(PAWN, BLACK);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			square[j][i].setFigureAndColor(EMPTY, NONE);

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			square[i][j].setcoordinateX(i);
			square[i][j].setcoordinateY(j);
		}

}

bool Board::playGame()
{
	system("cls");
	printBoard();
	return doMove();

}

bool Board::moveKing(Square* thisKing, Square* thatSpace) {
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	if (abs(thatSpace->getcoordinateX() - thisKing->getcoordinateX()) == 1)
		if (abs(thatSpace->getcoordinateY() - thisKing->getcoordinateY()) == 1)
		{
			thatSpace->setSpace(thisKing);
			thisKing->setEmpty();
			return true;
		}
		else return false;
	else return false;
}
bool Board::moveQueen(Square* thisQueen, Square* thatSpace) { //there might be problems with numbers of brackets
													   //off board inputs should be handled elsewhere (before this)
													   //squares with same color should be handled elsewhere (before this)

	int queenX = thisQueen->getcoordinateX();
	int queenY = thisQueen->getcoordinateY();
	int thatX = thatSpace->getcoordinateX();
	int thatY = thatSpace->getcoordinateY();
	std::cout << "this";
	int yIncrement;
	int xIncrement;

	bool invalid = false;
	if (queenX != thatX || queenY != thatY)
	{

		if (queenX == thatX)
		{
			yIncrement = (thatY - queenY) / (abs(thatY - queenY));
			for (int i = queenY + yIncrement; i != thatY; i += yIncrement)
			{

				if (square[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else
			if (queenY == thatY)
			{

				xIncrement = (thatX - queenX) / (abs(thatX - queenX));
				for (int i = queenX + xIncrement; i != thatX; i += xIncrement)
				{
					if (square[i][thatY].getColor() != NONE)
						return false;
				}
			}
			else
				if (abs(queenX - thatX) == abs(queenY - thatY))
				{
					xIncrement = (thatX - queenX) / (abs(thatX - queenX));
					yIncrement = (thatY - queenY) / (abs(thatY - queenY));

					for (int i = 1; i < abs(queenX - thatX); i++)
					{
						std::cout << "It got here somehow";
						if (square[queenX + xIncrement * i][queenY + yIncrement * i].getColor() != NONE)
							return false;

					}
				}
				else
					return false;
		//if()
	}



	if (invalid == false)
	{
		thatSpace->setSpace(thisQueen);
		thisQueen->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::moveBishop(Square* thisBishop, Square* thatSpace) { //there might be problems with number of brackets
	int bishopX = thisBishop->getcoordinateX();
	int bishopY = thisBishop->getcoordinateY();
	int thatX = thatSpace->getcoordinateX();
	int thatY = thatSpace->getcoordinateY();
	bool invalid = false;
	Square *s;
	if (abs(bishopX - thatX) == abs(bishopY - thatY))
	{
		int xIncrement = (thatX - bishopX) / (abs(thatX - bishopX));
		int yIncrement = (thatY - bishopY) / (abs(thatY - bishopY));

		for (int i = 1; i < abs(bishopX - thatX); i++)
		{
			std::cout << "It got here somehow";
			if (square[bishopX + xIncrement * i][bishopY + yIncrement * i].getColor() != NONE)
				return false;

		}
	}
	else
		return false;

	if (invalid == false)
	{
		thatSpace->setSpace(thisBishop);
		thisBishop->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}
bool Board::moveKnight(Square* thisKnight, Square* thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int knightX = thisKnight->getcoordinateX();
	int knightY = thisKnight->getcoordinateY();
	int thatX = thatSpace->getcoordinateX();
	int thatY = thatSpace->getcoordinateY();

	if ((abs(knightX - thatX) == 2 && abs(knightY - thatY) == 1) || (abs(knightX - thatX) == 1 && abs(knightY - thatY) == 2))
	{
		thatSpace->setSpace(thisKnight);
		thisKnight->setEmpty();
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::moveRook(Square* thisRook, Square* thatSpace)
{
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	int rookX = thisRook->getcoordinateX();
	int rookY = thisRook->getcoordinateY();
	int thatX = thatSpace->getcoordinateX();
	int thatY = thatSpace->getcoordinateY();
	bool invalid = false;
	if (rookX != thatX || rookY != thatY)
	{

		if (rookX == thatX)
		{
			int yIncrement = (thatY - rookY) / (abs(thatY - rookY));
			for (int i = rookY + yIncrement; i != thatY; i += yIncrement)
			{

				if (square[thatX][i].getColor() != NONE)
					return false;

			}
		}
		else
			if (rookY == thatY)
			{

				int xIncrement = (thatX - rookX) / (abs(thatX - rookX));
				for (int i = rookX + xIncrement; i != thatX; i += xIncrement)
				{
					if (square[i][thatY].getColor() != NONE)
						return false;
				}
			}
			else
				return false;
	}
	if (invalid == false)
	{
		thatSpace->setSpace(thisRook);
		thisRook->setEmpty();
		return true;
	}
	else
	{//Return some erorr or something. Probably return false;
		std::cout << "That is an invalid move for rook";
		return false;
	}
}

bool Board::movePawn(Square* thisPawn, Square* thatSpace) {
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	using namespace std;
	bool invalid = false;
	int pawnX = thisPawn->getcoordinateX();
	int pawnY = thisPawn->getcoordinateY();
	int thatX = thatSpace->getcoordinateX();
	int thatY = thatSpace->getcoordinateY();


	if (thisPawn->getColor() == WHITE)
	{

		if (pawnX == thatX && thatY == pawnY + 1 && thatSpace->getColor() == NONE)
		{
			thatSpace->setSpace(thisPawn);
			thisPawn->setEmpty();
			return true;
		}
		else
			if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY + 1 == thatY && thatSpace->getColor() == BLACK)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				return false;
	}
	else
		if (thisPawn->getColor() == BLACK)
		{
			if (pawnX == thatX && thatY == pawnY - 1 && thatSpace->getColor() == NONE)
			{
				thatSpace->setSpace(thisPawn);
				thisPawn->setEmpty();
				return true;
			}
			else
				if ((pawnX + 1 == thatX || pawnX - 1 == thatX) && pawnY - 1 == thatY && thatSpace->getColor() == WHITE)
				{
					thatSpace->setSpace(thisPawn);
					thisPawn->setEmpty();
					return true;
				}
				else
					return false;
		}
		else
			return false;
}
bool Board::makeMove(Position  startPosition, Position endPosition) {
	//Checking for turns will be done previous to this
	using namespace std;
	if (startPosition.getCoordinateX() < 0 || startPosition.getCoordinateX()>7 || startPosition.getCoordinateY() < 0 || startPosition.getCoordinateY()>7 || endPosition.getCoordinateX() < 0 || endPosition.getCoordinateX()>7 || endPosition.getCoordinateY() < 0 || endPosition.getCoordinateY()>8)
	{
		std::cout << "One of your inputs was our of bounds" << std::endl;
		return false;
	}
	Square* src = getSquare(startPosition);
	Square* dest = getSquare(endPosition);

	if (src->getColor() == dest->getColor() && dest->getColor() != NONE)
	{
		std::cout << "Invalid move: cannot land on your own piece" << std::endl;
		return false;
	}

	switch (src->getFigure())
	{
	case KING: return moveKing(src, dest);
		break;
	case QUEEN: return moveQueen(src, dest);
		break;
	case BISHOP: return moveBishop(src, dest);
		break;
	case KNIGHT: return moveKnight(src, dest);
		break;
	case ROOK: return moveRook(src, dest);
		break;
	case PAWN: return movePawn(src, dest);
		break;
	case EMPTY: std::cout << "You do not have a piece there" << std::endl;  return false;
		break;
	default: std::cerr << "Something went wrong in the switch statement in makeMove()" << std::endl;
		break;
	}
	return false;
}