#include "Piece.h"

//Default Constructor should remain unused
Piece::Piece() {
	setX(0);
	setY(0);
	setType('p');
}

void Piece::addTexture(char pieceType, bool player) {
	std::string path;
	if (player) { //is white
		switch (pieceType) {
		case 'p':
			path = "../PieceTextures/whitePawn.png";
			break;
		case 'h':
			path = "../PieceTextures/whiteKnight.png";
			break;
		case 'b':
			path = "../PieceTextures/whiteBishop.png";
			break;
		case 'r':
			path = "../PieceTextures/whiteRook.png";
			break;
		case 'q':
			path = "../PieceTextures/whiteQueen.png";
			break;
		case 'k' :
			path = "../PieceTextures/whiteKing.png";
			break;
		}
	} 
	else { //is black
		switch (pieceType) {
		case 'p':
			path = "../PieceTextures/blackPawn.png";
			break;
		case 'h':
			path = "../PieceTextures/blackKnight.png";
			break;
		case 'b':
			path = "../PieceTextures/blackBishop.png";
			break;
		case 'r':
			path = "../PieceTextures/blackRook.png";
			break;
		case 'q':
			path = "../PieceTextures/blackQueen.png";
			break;
		case 'k':
			path = "../PieceTextures/blackKing.png";
			break;
		}
	}
	std::cout << "Loaded texture" << std::endl;
	std::cout << texture.loadFromFile(path) <<  std::endl; 
	this->setTexture(texture);

	
	
}

void Piece::draw(sf::RenderWindow& window) {
	window.draw(*(dynamic_cast<Sprite*>(this)));
}

Piece::Piece(int xCoord, int yCoord, char pieceType, bool player) {
	this->setX(xCoord);
	this->setY(yCoord);
	this->setType(pieceType);
	this->setPlayer(player);

	this->addTexture(pieceType, player);
	
	this->setTexture(texture);
	this->setPosition((float)((xCoord * 127) + 10), (float)(yCoord * 127));

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