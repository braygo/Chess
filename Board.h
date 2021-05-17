#include "Piece.h"

class Board {
public:
	Board();

	void setBoardPtr(Piece* newPiecePtr);
	void setBoardPtr(int xCoord, int yCoord, Piece* newPiecePtr);
	

	Piece* getBoardPtr(int xCoord, int yCoord);
	

	void renderBoard(RenderWindow& window); //displays the black and white tiles
	void setBoard(RenderWindow& window); //sets intial piece positions
	void drawCurrentBoard(RenderWindow& window);

	bool checkMove(int startX, int startY, int endX, int endY);
	void movePiece(int startX, int startY, int endX, int endY);
private:
	Piece* board[8][8];
	
};