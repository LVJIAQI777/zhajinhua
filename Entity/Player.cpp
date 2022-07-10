//
// Created by Administrator on 2022/7/10.
//

#include "Player.h"

Player::Player() {}

Player::~Player() {

}

int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}


int Player::getSum() const {
    return sum;
}

void Player::setSum(int sum) {
    Player::sum = sum;
}

int *Player::getNum() const {
    return num;
}

void Player::setNum(int *num) {
    Player::num = num;
}
