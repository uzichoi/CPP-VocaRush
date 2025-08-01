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
    void placeWordsOnBoard(GameBoard& board); // ���� ���ο� ��ġ ���� ���Ե� Word�� ����
    void resetWordList();   // �ܾ� ����Ʈ �ʱ�ȭ
};

#endif // !WORDCONTROLLER_H
