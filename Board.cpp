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

	//Used for collision logic
	int tempX = 0;
	int tempY = 0;
	bool flag = false;
	int diffX = 0;
	int diffY = 0;
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
			else if ((endY + 1 == piece->getY() && abs(endX - piece->getX()) == 1) && (getBoardPtr(endX, endY) != nullptr && getBoardPtr(endX, endY)->getPlayer() != getBoardPtr(startX, startY)->getPlayer())) {
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

		if (((abs(endY - piece->getY()) == 2) && abs(endX - piece->getX()) == 1) ||
			(abs(endX - piece->getX()) == 2 && abs(endY - piece->getY()) == 1)) {
			if (getBoardPtr(endX, endY) == nullptr) {
				isValid = true;
			}
			else if (getBoardPtr(endX, endY)->getPlayer() != getBoardPtr(startX, startY)->getPlayer()) {
				isValid = true;
			}
		}
		break;
	case 'b':
		if (abs(endY - piece->getY()) == abs(endX - piece->getX())) {
			
				tempX = piece->getX();
				tempY = piece->getY();
				diffX = endX - piece->getX();
				diffY = endY - piece->getY();

				if (diffX > 0 && diffY < 0) { //up right
					tempX++;
					tempY--;
					while (tempX != endX && tempY != endY) {
						if (getBoardPtr(tempX, tempY) != nullptr) {
							flag = true;
						}
						tempX++;
						tempY--;
					}
				}
				if (diffX > 0 && diffY > 0) { //down right
					tempX++;
					tempY++;
					while (tempX != endX && tempY != endY) {
						if (getBoardPtr(tempX, tempY) != nullptr) {
							flag = true;
						}
						tempX++;
						tempY++;
					}
				}
				if (diffX < 0 && diffY < 0) { //up left
					tempX--;
					tempY--;
					while (tempX != endX && tempY != endY) {
						if (getBoardPtr(tempX, tempY) != nullptr) {
							flag = true;
						}
						tempX--;
						tempY--;
					}
				}
				if (diffX < 0 && diffY > 0) { //down left
					tempX--;
					tempY++;
					while (tempX != endX && tempY != endY) {
						if (getBoardPtr(tempX, tempY) != nullptr) {
							flag = true;
						}
						tempX--;
						tempY++;
					}
				}

				if (getBoardPtr(endX, endY) == nullptr) {
					isValid = true;
				} else if (getBoardPtr(endX, endY)->getPlayer() != getBoardPtr(startX, startY)->getPlayer()) {
					isValid = true;
				}
				
		}
		break;
	case 'r':
		if (endX == piece->getX() || endY == piece->getY()) {
			tempX = piece->getX();
			tempY = piece->getY();
			diffX = endX - piece->getX();
			diffY = endY - piece->getY();

			cout << "DiffX: " << diffX << "DiffY: " << diffY << endl;

			if (diffX == 0 && diffY < 0) { //up
				cout << "Rook moving up" << endl;
				tempY--;
				while (tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempY--;
				}
			}
			if (diffX == 0 && diffY > 0) { //down
				cout << "Rook moving down" << endl;
				tempY++;
				while (tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempY++;
				}
			}
			if (diffX < 0 && diffY == 0) { //left
				cout << "Rook moving left" << endl;
				tempX--;
				while (tempX != endX) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX--;
				}
			}
			if (diffX > 0 && diffY == 0) { //right
				cout << "Rook moving right" << endl;
				tempX++;
				while (tempX != endX) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX++;
				}
			}

			if (getBoardPtr(endX, endY) == nullptr) {
				isValid = true;
			}
			else if (getBoardPtr(endX, endY)->getPlayer() != getBoardPtr(startX, startY)->getPlayer()) {
				isValid = true;
			}
			
		}
		break;
	case 'q' :
		if (abs(endY - piece->getY()) == abs(endX - piece->getX()) || (endX == piece->getX() || endY == piece->getY())) {

			tempX = piece->getX();
			tempY = piece->getY();
			diffX = endX - piece->getX();
			diffY = endY - piece->getY();

			if (diffX > 0 && diffY < 0) { //up right
				tempX++;
				tempY--;
				while (tempX != endX && tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX++;
					tempY--;
				}
			}
			if (diffX > 0 && diffY > 0) { //down right
				tempX++;
				tempY++;
				while (tempX != endX && tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX++;
					tempY++;
				}
			}
			if (diffX < 0 && diffY < 0) { //up left
				tempX--;
				tempY--;
				while (tempX != endX && tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX--;
					tempY--;
				}
			}
			if (diffX < 0 && diffY > 0) { //down left
				tempX--;
				tempY++;
				while (tempX != endX && tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX--;
					tempY++;
				}
			}

			if (diffX == 0 && diffY < 0) { //up
				cout << "Rook moving up" << endl;
				tempY--;
				while (tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempY--;
				}
			}
			if (diffX == 0 && diffY > 0) { //down
				cout << "Rook moving down" << endl;
				tempY++;
				while (tempY != endY) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempY++;
				}
			}
			if (diffX < 0 && diffY == 0) { //left
				cout << "Rook moving left" << endl;
				tempX--;
				while (tempX != endX) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX--;
				}
			}
			if (diffX > 0 && diffY == 0) { //right
				cout << "Rook moving right" << endl;
				tempX++;
				while (tempX != endX) {
					if (getBoardPtr(tempX, tempY) != nullptr) {
						flag = true;
					}
					tempX++;
				}
			}

			if (getBoardPtr(endX, endY) == nullptr) {
				isValid = true;
			}
			else if (getBoardPtr(endX, endY)->getPlayer() != getBoardPtr(startX, startY)->getPlayer()) {
				isValid = true;
			}

		}
		break;
	}
	
	if (flag == true) {
		isValid = false;
		cout << "Piece collision detected" << endl;
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