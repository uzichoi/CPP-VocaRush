// BoardView.cpp

#include "GameBoardView.h"
#include "GameBoard.h"

GameBoardView::GameBoardView() { board = nullptr; } // 명시적 초기화

GameBoardView::~GameBoardView() {}

void GameBoardView::draw() {
    textcolor(BLACK, WHITE);

    int rows = board->getRow();
    int cols = board->getCol();

    int boxWidth = 50;
    int boxHeight = 25;     // player box와 통일
    
    // 게임 보드 시작 좌표(x, y) 계산
    int boxX = (consoleWidth - boxWidth) / 2;       // 30
    int boxY = (consoleHeight - boxHeight) / 2;     // 7

    // 보드 테두리 그리기
    drawBoxFill(boxX, boxY, boxX + boxWidth - 1, boxY + boxHeight - 1, BLACK); 
   
    // 보드 그리드 정렬용 시작 위치 계산
    // 셀 간 간격은 2칸(문자 + 공백 1칸 기준)
    int boardWidthInChars = cols * 2 - 1;
    int boardHeightInChars = rows;

    int startX = boxX + (boxWidth - boardWidthInChars) / 2; // 셀 폭 기준 수평 정렬
    int startY = boxY + (boxHeight - boardHeightInChars) / 2;   // 셀 높이 기준 수직 정렬

    textcolor(WHITE, BLACK); // fc: white, bc: black

    // 단어 출력
    for (int y = 0; y < rows; y++) {    
        gotoxy(startX + 1, startY + y); // y는 줄별 출력
        for (int x = 0; x < cols; x++) {
            if (board->isHighlighted(y, x)) 
                textcolor(CYAN1, BLACK);
            else 
                textcolor(WHITE, BLACK);

            cout << board->getCharAt(y, x);
            if (x < cols - 1) cout << ' ';  // 칸 사이 공백 출력
        }
    }

    textcolor(BLACK, WHITE);   // 원복
}

void GameBoardView::setBoard(GameBoard* board) { this-> board = board; }