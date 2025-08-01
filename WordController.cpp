// WordController.cpp

#include <random>
#include <algorithm>
#include "WordController.h"
#include "Word.h"
using namespace std;

WordController::WordController() {}


// Word 리스트 반환 (읽기 전용)
vector<Word>& WordController::getWordList() {
    return wordList;
}

// 외부 파일에서 단어들을 읽고, 랜덤하게 5개를 선택해 wordList에 저장
void WordController::loadWordsFromFile(const string& filename, int count) {
    ifstream fin(filename);    

    if (!fin) {
        cout << filename << " 파일 열기 실패" << endl;
        return;
    }

    string word;
    vector<string> allWords;    // 파일 내 모든 단어를 임시 저장할 벡터 컨테이너

    while (fin >> word) {   
        allWords.push_back(word);   // 파일 끝까지 단어를 읽어 allWords에 추가
    }

    // 무작위 섞기
    random_device rd;   // seed 역할
    mt19937 g(rd());    // 고성능 의사난수 생성기
    shuffle(allWords.begin(), allWords.end(), g);  // 단어를 무작위로 섞음

    wordList.clear();   // 기존 단어 목록 초기화

    for (int i = 0; i < count && i < allWords.size(); i++) {
        wordList.emplace_back(allWords[i]); // Word 생성자: Word(string text)
        // 앞에서 뽑은 랜덤 5개의 단어를 Word 객체로 변환해 WordList에 저장
    }

    sort(wordList.begin(), wordList.end(),
        [](Word& a, Word& b) { return a.getText().length() > b.getText().length(); });  // 람다식. 길이 순으로 정렬 (긴 단어부터)

    fin.close();
}

// 단어 리스트를 보드에 배치 (랜덤 방향, 위치 선택)
void WordController::placeWordsOnBoard(GameBoard& board) {
    // srand((unsigned int)time(0)); // 랜덤 초기화
    int maxAttempts = 100;  // 보드 최대 사이즈가 10*10이므로 최대 시도 횟수도 100회로 제한

    for (int i = 0; i < wordList.size(); i++) {
        Word& word = wordList[i];   

        bool placed = false;    // 배치 여부

        for (int attempt = 0; attempt < maxAttempts && !placed; attempt++) {
            int x = rand() % board.getCol();
            int y = rand() % board.getRow();

            Direction dir = static_cast<Direction>(rand() % 3); 
            // 0~2 무작위 난수 생성
            // int를 Direction이라는 사용자 정의 타입으로 명시적 형변환
            // 즉, 0, 1, 2 중 하나를 무작위로 골라서 Direction이라는 방향 타입(HORIZONTAL, VERTICAL, DIAGONAL)으로 변환한 뒤, dir이라는 변수에 저장라는 의미.
        
            word.setPosition(x, y, dir); // Word 내부에 위치 및 방향 저장

            if (board.canPlaceWord(word)) {
                board.placeWord(word.getText(), x, y, dir); // 실제 보드에 삽입
                placed = true;  // 배치 성공 마킹
            }
        }

        if (!placed) {  // 모든 시도 실패 시 경고 문구 출력
            cout << word.getText() << " 단어 배치에 실패하였습니다. " << endl;
        }
    }
}

void WordController::resetWordList() {
    wordList.clear();
}