#include "Board.h"

Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = nullptr;
		}
	}
}


void Board::setBoardPtr(Piece* ptr) {
	board[ptr->getX()][ptr->getY()] = ptr;
}

Piece* Board::getBoardPtr(int xCoord, int yCoord) {
	return board[xCoord][yCoord];
}

void Board::setBoard(RenderWindow& window) {
	//Black Pieces
	for (int i = 0; i < 8; i++) {
		setBoardPtr(new Piece(i, 1, 'p', false));
	}
	setBoardPtr(new Piece(0, 0, 'r', false));
	setBoardPtr(new Piece(7, 0, 'r', false));
	setBoardPtr(new Piece(1, 0, 'h', false));
	setBoardPtr(new Piece(6, 0, 'h', false));
	setBoardPtr(new Piece(2, 0, 'b', false));
	setBoardPtr(new Piece(5, 0, 'b', false));
	setBoardPtr(new Piece(3, 0, 'q', false));
	setBoardPtr(new Piece(4, 0, 'k', false));

	//White Pieces
	for (int i = 0; i < 8; i++) {
		setBoardPtr(new Piece(i, 6, 'p', true));
	}
	setBoardPtr(new Piece(0, 7, 'r', true));
	setBoardPtr(new Piece(7, 7, 'r', true));
	setBoardPtr(new Piece(1, 7, 'h', true));
	setBoardPtr(new Piece(6, 7, 'h', true));
	setBoardPtr(new Piece(2, 7, 'b', true));
	setBoardPtr(new Piece(5, 7, 'b', true));
	setBoardPtr(new Piece(3, 7, 'q', true));
	setBoardPtr(new Piece(4, 7, 'k', true));



}

void Board::renderBoard(sf::RenderWindow& window) {
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			sf::RectangleShape square(sf::Vector2f(128, 128));
			if (j % 2 == 0) {
				if (i % 2 != 0) {
					square.setFillColor(sf::Color::Black);
				}
			}
			else {
				if (i % 2 == 0) {
					square.setFillColor(sf::Color::Black);
				}
			}
			square.setPosition((float)(i * 128), (float)(j * 128));
			window.draw(square);
		}
	}
}

void Board::drawCurrentBoard(RenderWindow& window) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != nullptr) {
				board[i][j]->draw(window);
				
			}
		}
	}
}