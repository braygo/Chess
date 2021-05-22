#include "Board.h"

class ChessGame {
public:
	ChessGame();

	void runGame();

	void setPieceSelected(Piece* newPiece);
	void setTurn(bool tf);
	void setWinner(int val);
	
	Piece* getPieceSelected();
	bool getTurn();
	int getWinner();

private:
	Board gameboard;
	Piece* pieceSelected;
	bool turn; //true == white, false == black
	int winner; //0 == null, 1 == white, 2 == black
};