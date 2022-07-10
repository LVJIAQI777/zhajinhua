
#include <iostream>
#include <cstdlib>
#include "Poker.h"
#include "../Utils/Random_f.h"

using namespace std;

Poker::Poker() {
    Color[0] = "∫ÏÃ“";
    Color[1] = "∑Ω∆¨";
    Color[2] = "∫⁄Ã“";
    Color[3] = "√∑ª®";
    Size[0] = "1";
    Size[1] = "2";
    Size[2] = "3";
    Size[3] = "4";
    Size[4] = "5";
    Size[5] = "6";
    Size[6] = "7";
    Size[7] = "8";
    Size[8] = "9";
    Size[9] = "10";
    Size[10] = "11";
    Size[11] = "12";
    Size[12] = "13";
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            All_poker[4 * i + j] = {Color[j], Size[i]};
        }
    }
}

Poker::~Poker() {
}

void Poker::shuffle_All_poker() {
    int *disorder = random_list(52);
    for (int i = 0; i < 52; i++) {
        A_poker temp = All_poker[disorder[i]];
        All_poker[disorder[i]] = All_poker[i];
        All_poker[i] = temp;
    }

    delete[] disorder;
}

void Poker::display_All_poker() {
    for (int i = 0; i < 52; i++) {
        cout << "[" << All_poker[i].p_color << "-" << All_poker[i].p_size << "]" << endl;
    }
}

string Poker::generate_A_poker(int num) {
    cout << "[" << All_poker[num].p_color << "-" << All_poker[num].p_size << "]" << endl;
    return All_poker[num].p_size;

}

void Poker::deal_poker(Player *players, int id) {
    A_poker Player_pokers[3];
    int *num = random_list(3);
    int *numTemp = new int[3];
    int sumTemp = 0;
    for (int i = 0; i < 3; i++) {
        string size = generate_A_poker(num[i]);
        numTemp[i] = atoi(size.c_str());
        sumTemp = sumTemp + numTemp[i];
    }
    players[id].setSum(sumTemp);
    delete[] num;
//    return players;
}

void Poker::test(Player players,int n) {
    Player p11;
    players.setSum(n);
    cout<<"iner:"<<players.getSum()<<endl;

}
