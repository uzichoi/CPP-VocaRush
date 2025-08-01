// WordController.cpp

#include <random>
#include <algorithm>
#include "WordController.h"
#include "Word.h"
using namespace std;

WordController::WordController() {}


// Word ����Ʈ ��ȯ (�б� ����)
vector<Word>& WordController::getWordList() {
    return wordList;
}

// �ܺ� ���Ͽ��� �ܾ���� �а�, �����ϰ� 5���� ������ wordList�� ����
void WordController::loadWordsFromFile(const string& filename, int count) {
    ifstream fin(filename);    

    if (!fin) {
        cout << filename << " ���� ���� ����" << endl;
        return;
    }

    string word;
    vector<string> allWords;    // ���� �� ��� �ܾ �ӽ� ������ ���� �����̳�

    while (fin >> word) {   
        allWords.push_back(word);   // ���� ������ �ܾ �о� allWords�� �߰�
    }

    // ������ ����
    random_device rd;   // seed ����
    mt19937 g(rd());    // ���� �ǻ糭�� ������
    shuffle(allWords.begin(), allWords.end(), g);  // �ܾ �������� ����

    wordList.clear();   // ���� �ܾ� ��� �ʱ�ȭ

    for (int i = 0; i < count && i < allWords.size(); i++) {
        wordList.emplace_back(allWords[i]); // Word ������: Word(string text)
        // �տ��� ���� ���� 5���� �ܾ Word ��ü�� ��ȯ�� WordList�� ����
    }

    sort(wordList.begin(), wordList.end(),
        [](Word& a, Word& b) { return a.getText().length() > b.getText().length(); });  // ���ٽ�. ���� ������ ���� (�� �ܾ����)

    fin.close();
}

// �ܾ� ����Ʈ�� ���忡 ��ġ (���� ����, ��ġ ����)
void WordController::placeWordsOnBoard(GameBoard& board) {
    // srand((unsigned int)time(0)); // ���� �ʱ�ȭ
    int maxAttempts = 100;  // ���� �ִ� ����� 10*10�̹Ƿ� �ִ� �õ� Ƚ���� 100ȸ�� ����

    for (int i = 0; i < wordList.size(); i++) {
        Word& word = wordList[i];   

        bool placed = false;    // ��ġ ����

        for (int attempt = 0; attempt < maxAttempts && !placed; attempt++) {
            int x = rand() % board.getCol();
            int y = rand() % board.getRow();

            Direction dir = static_cast<Direction>(rand() % 3); 
            // 0~2 ������ ���� ����
            // int�� Direction�̶�� ����� ���� Ÿ������ ����� ����ȯ
            // ��, 0, 1, 2 �� �ϳ��� �������� ��� Direction�̶�� ���� Ÿ��(HORIZONTAL, VERTICAL, DIAGONAL)���� ��ȯ�� ��, dir�̶�� ������ ������ �ǹ�.
        
            word.setPosition(x, y, dir); // Word ���ο� ��ġ �� ���� ����

            if (board.canPlaceWord(word)) {
                board.placeWord(word.getText(), x, y, dir); // ���� ���忡 ����
                placed = true;  // ��ġ ���� ��ŷ
            }
        }

        if (!placed) {  // ��� �õ� ���� �� ��� ���� ���
            cout << word.getText() << " �ܾ� ��ġ�� �����Ͽ����ϴ�. " << endl;
        }
    }
}

void WordController::resetWordList() {
    wordList.clear();
}