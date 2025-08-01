// PlayerView.cpp

#include "PlayerView.h"

void PlayerView::draw() {}

void PlayerView::draw(int index, Player& player) {
	// index=0 : player[0] 좌측 영역
	// index=1 : player[1] 우측 영역

	int boxWidth = 20;
	int boxHeight = 25;
	int boxX = 0;
	int boxY = 7;

	switch (index) {
	case 0:
		boxX = (consoleWidth / 2 - 25) - spacingBetweenBoxes - boxWidth;
		break;
	case 1:
		boxX = (consoleWidth / 2 + 25) + spacingBetweenBoxes;
		break;
	default:
		cout << "Invalid index!\n";
		return;
	}

	drawBox(boxX, boxY, boxX + boxWidth - 1, boxY + boxHeight - 1);

	gotoxy(boxX + spacingBetweenLines, boxY + spacingBetweenLines);
	cout << "Player " << index + 1 << endl;		// 플레이어 1,2 구분용 헤더 
	
	for (int i = 1; i < boxWidth - 1; i++) {
		gotoxy(boxX + i, boxY + spacingBetweenLines + spacingBetweenLines);	// 헤더 구분선
		cout << "─";
	}

	string lables[] = {		// 플레이어 라벨
		"Name : ", "",
		"Score : ", "",
		"Combo : ", "",
		"Max Combo : ", "",
		"HP : "
	};

	string values[] = {		// 플레이어 실제 정보
		player.getName(), "",
		to_string(player.getScore()), "",
		to_string(player.getCombo()), "",
		to_string(player.getMaxCombo()), "",
		to_string(player.getHP())
	};

	int textX = boxX + spacingBetweenLines;	
	int textY = boxY + spacingBetweenLines * 3 + 2;	// 2는 박스 내부에서 상하 중앙 정렬을 위한 상수

	for (int i = 0; i < 9; i++) {
		gotoxy(textX, textY + i);	
		cout << lables[i] << values[i] << endl;
	}

}

void PlayerView::draw(int index, Player& player, bool isActive) {
	if (isActive)
		textcolor(WHITE, YELLOW1);  // 현재 턴 플레이어 강조
	else
		textcolor(BLACK, WHITE);
}