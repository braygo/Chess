#include "ChessGame.h"

void ChessGame::runGame(void) {
	RenderWindow window(VideoMode(1024, 1024), "C++ Chess", Style::Close | Style::Titlebar);

	Board gameboard;
	gameboard.setBoard(window);

	int currentXCoord = 0;
	int currentYCoord = 0;
	while (window.isOpen()) {

		gameboard.renderBoard(window);
		gameboard.drawCurrentBoard(window);

		window.display();

		Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::TextEntered:
				if (evnt.text.unicode < 128) {
					printf("%c", evnt.text.unicode);
				}
				gameboard.movePiece(0, 0, 2, 4);
				break;
			case Event::MouseButtonPressed:
				if ((evnt.mouseButton.x >= 0 && evnt.mouseButton.x <= 1024) && (evnt.mouseButton.y >= 0 && evnt.mouseButton.y <= 1024)) {
					currentXCoord = evnt.mouseButton.x / 128;
					currentYCoord = evnt.mouseButton.y / 128;
					Piece* currentPiece = gameboard.getBoardPtr(currentXCoord, currentYCoord);

					//Selecting phase
					if (getPieceSelected() == nullptr && currentPiece != nullptr) { 
						setPieceSelected(currentPiece);
						std::cout << "Piece Selected" << std::endl;
					}
					//Movement phase
					else if(getPieceSelected() != nullptr){ 
						Piece* selectedPiece = getPieceSelected();
						if (gameboard.checkMove(selectedPiece->getX(), selectedPiece->getY(), currentXCoord, currentYCoord)) {
							gameboard.movePiece(selectedPiece->getX(), selectedPiece->getY(), currentXCoord, currentYCoord);
						}
						else {
							cout << "Invalid Move" << endl;
						}
						setPieceSelected(nullptr);
					}
					
				}
					break;
				}
			}		
	}
}

void ChessGame::setPieceSelected(Piece* newPiece) {
	pieceSelected = newPiece;
}

Piece* ChessGame::getPieceSelected() {
	return pieceSelected;
}

