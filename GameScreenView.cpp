// GameScreenView.cpp

#include "GameScreenView.h"

void GameScreenView::draw() {
	cls(WHITE, BLACK);

	string title[] = {
		" _ _   _    __   _    ___  _ _  __  _ _ ",
		"| | | / \\  / _| / \\  | o \\| | |/ _|| U |",
		"| V |( o )( (_ | o | |   /| U |\\_ \\|   |",
		" \\_/  \\_/  \\__||_n_| |_|\\\\|___| __/|_n_|",
		"                                        "
	};

	int maxLineLength = title[0].length(); // 첫 번째 줄 길이
	int artX = (consoleWidth - maxLineLength) / 2;  // 아스키 아트 시작 x좌표

	textcolor(GREEN1, WHITE);	
	for (int i = 0; i < 5; i++) {
		gotoxy(artX, 1 + i);
		cout << title[i] << endl;
	}
	textcolor(BLACK, WHITE);
}