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

void Board::setBoardPtr(int xCoord, int yCoord, Piece* newPiecePtr) {
	board[xCoord][yCoord] = newPiecePtr;
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

bool Board::checkMove(int startX, int startY, int endX, int endY) {
	Piece* piece = this->getBoardPtr(startX, startY);
	bool isValid = false;
	switch (piece->getType()) {
	case 'p':
		if (piece->getPlayer()) { //white
			//normal movement
			if (getBoardPtr(endX, endY) == nullptr) {
				if (endY + 1 == piece->getY() && endX == piece->getX()) {
					isValid = true;
				}
				//starting jump movement
				else if ((endY + 2 == piece->getY() && endX == piece->getX()) && piece->getHasMoved() == false) {
					isValid = true;
				}
			} 
			//attacking
			else if ((endY + 1 == piece->getY() && abs(endX - piece->getX()) == 1) && (getBoardPtr(endX, endY) != nullptr && getBoardPtr(endX,endY)->getPlayer() != getBoardPtr(startX, startY)->getPlayer())) {
				isValid = true;
			}
		}
		else { //black
			if (getBoardPtr(endX, endY) == nullptr) {
				if (endY - 1 == piece->getY() && endX == piece->getX()) {
					isValid = true;
				}
				//starting jump movement
				else if ((endY - 2 == piece->getY() && endX == piece->getX()) && piece->getHasMoved() == false) {
					isValid = true;
				}
			}
			//attacking
			else if ((endY - 1 == piece->getY() && abs(endX - piece->getX()) == 1) && (getBoardPtr(endX, endY) != nullptr && getBoardPtr(endX, endY)->getPlayer() != getBoardPtr(startX, startY)->getPlayer())) {
				isValid = true;
			}
		}
		break;
	case 'h':
		
		if (((abs(endY - piece->getY()) == 2)&& abs(endX - piece->getX()) == 1) ||
			(abs(endX - piece->getX()) == 2 && abs(endY - piece->getY()) == 1)) {
			if (getBoardPtr(endX, endY) == nullptr) {
				isValid = true;
			}
		}
		break;
	}
	return isValid;
}


void Board::movePiece(int startX, int startY, int endX, int endY) {
	Piece* temp = board[startX][startY];
	temp->setPosition((float)((endX * 127) + 10), (float)(endY * 127));
	temp->setX(endX);
	temp->setY(endY);
	temp->setHasMoved(true);
	setBoardPtr(endX, endY, temp);
	setBoardPtr(startX, startY, nullptr);
	
	
}