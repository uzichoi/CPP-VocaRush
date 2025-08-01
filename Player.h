// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class PlayerView;   // ���� ����

using namespace std;

class Player {
    friend class PlayerView;
    PlayerView* playerView;
    string name;
    int score;
    int combo;
    int maxCombo;
    int HP;
public:
    Player();
    ~Player();
    PlayerView* getPlayerView();  // getter ����
    void addScore(int points);
    void addCombo();
    void subHP();
    void setCombo(int combo);
    void setMaxCombo(int maxCombo);
    void setName(string name);
    void setHP(int hp);
    void setScore(int score);
    string getName();
    int getScore();
    int getCombo();
    int getMaxCombo();
    int getHP();
};

#endif // PLAYER_H