#include "Board.h"

Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = nullptr;
		}
	}
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