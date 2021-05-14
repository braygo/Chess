#include "Piece.h"

class Board {
public:
	Board();

	void renderBoard(sf::RenderWindow& window);
private:
	Piece* board[8][8];
};