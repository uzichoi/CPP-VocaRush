// PlayerView.cpp

#include "PlayerView.h"

void PlayerView::draw() {}

void PlayerView::draw(int index, Player& player) {
	// index=0 : player[0] ���� ����
	// index=1 : player[1] ���� ����

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
	cout << "Player " << index + 1 << endl;		// �÷��̾� 1,2 ���п� ��� 
	
	for (int i = 1; i < boxWidth - 1; i++) {
		gotoxy(boxX + i, boxY + spacingBetweenLines + spacingBetweenLines);	// ��� ���м�
		cout << "��";
	}

	string lables[] = {		// �÷��̾� ��
		"Name : ", "",
		"Score : ", "",
		"Combo : ", "",
		"Max Combo : ", "",
		"HP : "
	};

	string values[] = {		// �÷��̾� ���� ����
		player.getName(), "",
		to_string(player.getScore()), "",
		to_string(player.getCombo()), "",
		to_string(player.getMaxCombo()), "",
		to_string(player.getHP())
	};

	int textX = boxX + spacingBetweenLines;	
	int textY = boxY + spacingBetweenLines * 3 + 2;	// 2�� �ڽ� ���ο��� ���� �߾� ������ ���� ���

	for (int i = 0; i < 9; i++) {
		gotoxy(textX, textY + i);	
		cout << lables[i] << values[i] << endl;
	}

}

void PlayerView::draw(int index, Player& player, bool isActive) {
	if (isActive)
		textcolor(WHITE, YELLOW1);  // ���� �� �÷��̾� ����
	else
		textcolor(BLACK, WHITE);
}