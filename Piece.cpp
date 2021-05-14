#include "Piece.h"

//Default Constructor should remain unused
Piece::Piece() {
	setX(0);
	setY(0);
	setType('p');
}

Piece::Piece(int xCoord, int yCoord, char pieceType, bool player) {
	this->setX(xCoord);
	this->setY(yCoord);
	this->setType(pieceType);
	this->setPlayer(player);

	if (player) { //is white
		switch (pieceType) {
		case 'p':
			break;
		default:

			break;
		}
	}
	else { //is black

	}

}

void Piece::setX(int val) {
	xCoord = val;
}

void Piece::setY(int val) {
	yCoord = val;
}

void Piece::setType(char val) {
	pieceType = val;
}

void Piece::setPlayer(bool val) {
	player = val;
}

int Piece::getX(void) {
	return xCoord;
}

int Piece::getY(void) {
	return yCoord;
}

char Piece::getType(void) {
	return pieceType;
}

bool Piece::getPlayer(void) {
	return player;
}