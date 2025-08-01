// WordController.h

#ifndef WORDCONTROLLER_H
#define WORDCONTROLLER_H

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include "Word.h"
#include "GameBoard.h"

class WordController {
    vector<Word> wordList;
public:
    WordController();
    vector<Word>& getWordList();
    void loadWordsFromFile(const string& filename, int count);
    void placeWordsOnBoard(GameBoard& board); // 보드 내부에 위치 정보 포함된 Word들 삽입
    void resetWordList();   // 단어 리스트 초기화
};

#endif // !WORDCONTROLLER_H
