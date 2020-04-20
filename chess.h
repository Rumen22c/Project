#pragma once
#include<iostream>
#include<cmath>
#include<string>

enum   Figure { KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, EMPTY };
enum   Color { WHITE, BLACK, NONE };

class Position {
	int coordinateX, coordinateY;
	
public:
	
	Position() {
		coordinateX = 0;
		coordinateY = 0;
	}
	Position(int x, int y) {
		coordinateX = x;
		coordinateY = y;
	}
	void setCoordinateX(int x) {
		coordinateX = x;
	}
	void setCoordinateY(int y) {
		coordinateY = y;
	}
	int getCoordinateX() {
		return coordinateX;
	}
	int getCoordinateY() {
		return coordinateY;
	}
	Position(const Position& other) {
		this->coordinateX = other.coordinateX;
		this->coordinateY = other.coordinateY;
	 }
   Position& operator=(const Position& other) {
	   
	   this->coordinateX = other.coordinateX;
	   this->coordinateY = other.coordinateY;
	   return *this;
   }
};
class   Square
{

	Figure   figure;
	Color   color;
	
	Position positionOnTheTable;
public:
	void   setSpace(Square *);
	void   setEmpty();
	void   setFigureAndColor(Figure, Color);
	Figure   getFigure();
	Color   getColor();
	//void   setcoordinateX(int   x) {positionOnTheTable.setCoordinateX(x); }
	//void   setcoordinateY(int   y) { positionOnTheTable.setCoordinateY(y); }
	void setCoordinates(int x, int y);
	int   getcoordinateX() { return  positionOnTheTable.getCoordinateX(); }
	int   getcoordinateY() { return   positionOnTheTable.getCoordinateX(); }
	Square();
};

class   Board
{
	Square   square[8][8];
	Color   turn = WHITE;
	

	bool   isPossibleToMoveKing(Square* thisKing, Square* thatSpace);
	bool   isPossibleToMoveQueen(Square *   thisQueen, Square *   thatSpace);
	bool   isPossibleToMoveBishop(Square *   thisBishop, Square *   thatSpace);
	bool   isPossibleToMoveKnight(Square *   thisKnight, Square *   thatSpace);
	bool   isPossibleToMoveRook(Square *   thisRook, Square *   thatSpace);
	bool   isPossibleToMovePawn(Square *   thisPawn, Square *   thatSpace);

	void   moveKing(Square* thisKing, Square* thatSpace);
	void   moveQueen(Square *   thisQueen, Square *   thatSpace);
	void   moveBishop(Square *   thisBishop, Square *   thatSpace);
	void   moveKnight(Square *   thisKnight, Square *   thatSpace);
    void   moveRook(Square *   thisRook, Square *   thatSpace);
	void   movePawn(Square *   thisPawn, Square *   thatSpace);
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
 






