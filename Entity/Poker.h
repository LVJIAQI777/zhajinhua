#ifndef POKER_H
#define POKER_H

#include <string>
#include "Player.h"

class Poker
{
private:
    std::string Color[4];
    std::string Size[13];
    struct A_poker
    {
        std::string p_color;
        std::string p_size;
    };
    A_poker All_poker[52];
public:
    Poker();  //????????
    ~Poker();  //????????
    void display_All_poker();  //????????
    void shuffle_All_poker();  //???
    std::string generate_A_poker(int num);  //????????
    void deal_poker(Player* players,int id);  //????
    void test(Player players,int n);
};

#endif
