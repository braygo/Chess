#include "Board.h"

class ChessGame {
public:
//	ChessGame();

	void runGame();

	void setPieceSelected(Piece* newPiece);
	Piece* getPieceSelected();
private:
	Board gameboard;
	Piece* pieceSelected;
};