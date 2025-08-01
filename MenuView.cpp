#include "MenuView.h"

MenuView::MenuView() {}

MenuView::~MenuView() {}

void MenuView::draw() {
    cls(15, 0);     // bg: white, fc: black

    // 박스 크기 설정 (내용에 맞게 조절)
    int boxWidth = 60;
    int boxHeight = 18;
    int boxX = (consoleWidth - boxWidth) / 2;   // 박스를 화면 가로 중앙에 배치
    int boxY = (consoleHeight - boxHeight) / 2 - 2; // 세로 중앙보다 2칸 위에 배치

    drawBox(boxX, boxY, boxX + boxWidth - 1, boxY + boxHeight - 1);

    // 제목 "How to Play"
    string titleMsg = "How to Play";
    int titleX = boxX + (boxWidth - titleMsg.length()) / 2;
    gotoxy(titleX, boxY + 2);
    cout << titleMsg;

    // 제목 아래 구분선 (수평선만 그리기)
    for (int i = boxX + 1; i < boxX + boxWidth - 1; i++) {
        gotoxy(i, boxY + 3);
        cout << "─";
    }
    gotoxy(boxX, boxY + 3); cout << "├";
    gotoxy(boxX + boxWidth - 1, boxY + 3); cout << "┤";

    // 게임 설명 내용들
    string instructions[] = {
        "1. 2인 배틀형 단어 찾기 게임입니다.",
        "",
        "2. 키를 먼저 누른 사람이 입력 기회를 가집니다.",
        "   Player 1: 'A' / Player 2 : 'L' 키 사용",
        "",
        "3. 입력 제한 시간은 3초입니다.",
        "",
        "4. 보스 단어를 찾으면 추가 점수를 획득합니다.",
        "",
        "5. 연속 정답 시 콤보로 점수 상승!"
    };

    int numInstructions = 10;

    // 설명 내용 출력
    for (int i = 0; i < numInstructions; i++) {
        if (instructions[i].length() > 0) {
            gotoxy(boxX + 3, boxY + 5 + i);
            cout << instructions[i];
        }
    }

    // 하단 안내 메시지
    string backMsg = "Press ESC to go back to start page";
    int backX = (consoleWidth - backMsg.length()) / 2;
    gotoxy(backX, boxY + 22);
    textcolor(3, 15);
    cout << backMsg;
}