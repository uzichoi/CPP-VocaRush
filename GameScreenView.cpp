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

	int maxLineLength = title[0].length(); // ù ��° �� ����
	int artX = (consoleWidth - maxLineLength) / 2;  // �ƽ�Ű ��Ʈ ���� x��ǥ

	textcolor(GREEN1, WHITE);	
	for (int i = 0; i < 5; i++) {
		gotoxy(artX, 1 + i);
		cout << title[i] << endl;
	}
	textcolor(BLACK, WHITE);
}