#include "MenuView.h"

MenuView::MenuView() {}

MenuView::~MenuView() {}

void MenuView::draw() {
    cls(15, 0);     // bg: white, fc: black

    // �ڽ� ũ�� ���� (���뿡 �°� ����)
    int boxWidth = 60;
    int boxHeight = 18;
    int boxX = (consoleWidth - boxWidth) / 2;   // �ڽ��� ȭ�� ���� �߾ӿ� ��ġ
    int boxY = (consoleHeight - boxHeight) / 2 - 2; // ���� �߾Ӻ��� 2ĭ ���� ��ġ

    drawBox(boxX, boxY, boxX + boxWidth - 1, boxY + boxHeight - 1);

    // ���� "How to Play"
    string titleMsg = "How to Play";
    int titleX = boxX + (boxWidth - titleMsg.length()) / 2;
    gotoxy(titleX, boxY + 2);
    cout << titleMsg;

    // ���� �Ʒ� ���м� (���򼱸� �׸���)
    for (int i = boxX + 1; i < boxX + boxWidth - 1; i++) {
        gotoxy(i, boxY + 3);
        cout << "��";
    }
    gotoxy(boxX, boxY + 3); cout << "��";
    gotoxy(boxX + boxWidth - 1, boxY + 3); cout << "��";

    // ���� ���� �����
    string instructions[] = {
        "1. 2�� ��Ʋ�� �ܾ� ã�� �����Դϴ�.",
        "",
        "2. Ű�� ���� ���� ����� �Է� ��ȸ�� �����ϴ�.",
        "   Player 1: 'A' / Player 2 : 'L' Ű ���",
        "",
        "3. �Է� ���� �ð��� 3���Դϴ�.",
        "",
        "4. ���� �ܾ ã���� �߰� ������ ȹ���մϴ�.",
        "",
        "5. ���� ���� �� �޺��� ���� ���!"
    };

    int numInstructions = 10;

    // ���� ���� ���
    for (int i = 0; i < numInstructions; i++) {
        if (instructions[i].length() > 0) {
            gotoxy(boxX + 3, boxY + 5 + i);
            cout << instructions[i];
        }
    }

    // �ϴ� �ȳ� �޽���
    string backMsg = "Press ESC to go back to start page";
    int backX = (consoleWidth - backMsg.length()) / 2;
    gotoxy(backX, boxY + 22);
    textcolor(3, 15);
    cout << backMsg;
}