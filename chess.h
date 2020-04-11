#pragma once
#include<iostream>
#include<cmath>
#include<string>

enum   Figure { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum   Color { WHITE, BLACK, NONE };

class Position {
public:
	int coordinateX, coordinateY;
	Position() {
		coordinateX = 0;
		coordinateY = 0;
	}
	Position(int x, int y) {
		coordinateX = x;
		coordinateY = y;
	}
	int getCoordinateX() {
		return coordinateX;
	}
	int getCoordinateY() {
		return coordinateY;
	}
	void setCoordinateX(int x) {
		coordinateX = x;
	}
	void setCoordinateY(int y) {
		coordinateY = y;
	}
};
class   Square
{

	Figure   figure;
	Color   color;
	//int   coordinateX, coordinateY;
	Position positionOnTheTable;
public:
	void   setSpace(Square *);
	void   setEmpty();
	void   setFigureAndColor(Figure, Color);
	Figure   getFigure();
	Color   getColor();
	void   setcoordinateX(int   x) {positionOnTheTable.setCoordinateX(x); }
	void   setcoordinateY(int   y) { positionOnTheTable.setCoordinateY(y); }
	int   getcoordinateX() { return  positionOnTheTable.getCoordinateX(); }
	int   getcoordinateY() { return   positionOnTheTable.getCoordinateX(); }
	Square();
};

class   Board
{
	Square   square[8][8];
	Color   turn = WHITE;
	//bool   isPossibleToMoveKing(Square *   thisKing, Square *   thatSpace);

	bool   moveKing(Square* thisKing, Square* thatSpace);
	bool   moveQueen(Square *   thisQueen, Square *   thatSpace);
	bool   moveBishop(Square *   thisBishop, Square *   thatSpace);
	bool   moveKnight(Square *   thisKnight, Square *   thatSpace);
	bool   moveRook(Square *   thisRook, Square *   thatSpace);
	bool   movePawn(Square *   thisPawn, Square *   thatSpace);
	bool   makeMove(Position  startPosition, Position endPosition);
	void   printBoard();
public:
	Square *   getSquare(Position positionOnTheTable) {
		return   &square[positionOnTheTable.getCoordinateX()][positionOnTheTable.getCoordinateY()];
	}
	void   setSquare(Square   *   s, Position positionOnTheTable) {
		square[positionOnTheTable.getCoordinateX()][positionOnTheTable.getCoordinateY()] = *s;
	}
	bool   doMove();

	void   setBoard();
	bool   playGame();
};
 






