#include "Piece.h"

class Board {
public:
	Board();

	void setBoardPtr(Piece* newPiecePtr);
	Piece* getBoardPtr(int xCoord, int yCoord);

	void renderBoard(RenderWindow& window); //displays the black and white tiles
	void setBoard(RenderWindow& window); //sets intial piece positions
	void drawCurrentBoard(RenderWindow& window);
private:
	Piece* board[8][8];
};