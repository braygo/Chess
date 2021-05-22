#include "Board.h"

class ChessGame {
public:
//	ChessGame();

	void runGame();

	void setPieceSelected(Piece* newPiece);
	Piece* getPieceSelected();

	void setTurn(bool tf);
	bool getTurn(void);
private:
	Board gameboard;
	Piece* pieceSelected;
	bool turn; //true == white, false == black
};