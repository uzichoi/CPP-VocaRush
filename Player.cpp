// Player.cpp

#include "Player.h"
#include "PlayerView.h"

Player::Player() {
    playerView = new PlayerView();
    score = 0;
    combo = 0;
    maxCombo = 0;
    HP = 3;
}

Player::~Player() { delete playerView; }

PlayerView* Player::getPlayerView() { 
    return playerView;
}  


void Player::addScore(int points) { 
    if (combo > 0)
        score += points * combo;
    else
        score += points;
}

void Player::addCombo() {
    combo++;
    if (combo > maxCombo)
        maxCombo = combo;   // 최대 콤보 갱신
}

void Player::subHP() { HP--; }

void Player::setCombo(int combo) { this->combo = combo;  }

void Player::setMaxCombo(int maxCombo) { this->maxCombo = maxCombo; }

void Player::setName(string name) { this->name = name; }

void Player::setHP(int hp) { this->HP = hp; }

void Player::setScore(int score) { this->score = score; }

string Player::getName() { return name; }

int Player::getScore() { return score; }

int Player::getCombo() { return combo; }

int Player::getMaxCombo() { return maxCombo; }

int Player::getHP() { return HP; }