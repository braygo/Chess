#include "ChessGame.h"

void ChessGame::runGame(void) {
	RenderWindow window(VideoMode(1024, 1024), "C++ Chess", Style::Close | Style::Titlebar);

	Board gameboard;
	gameboard.setBoard(window);
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
				case sf::Event::TextEntered:
					if (evnt.text.unicode < 128) {
						printf("%c", evnt.text.unicode);
					}
					break;
				}
			}
			
	}
}