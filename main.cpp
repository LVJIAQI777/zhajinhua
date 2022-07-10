
#include "Entity/Player.h"
#include "Entity/Poker.h"

#include <iostream>
#include <conio.h>
#include <string>


using namespace std;

int main() {
    srand(time(0));  //生成随机数种子，保证随机数不同
    int num_player;
    bool sign = true;
    cout << "欢迎进入《炸金花》游戏！" << endl;
    Poker A;
    Player *players;
    while (sign) {
        cout << "请输入玩家人数：";
        cin >> num_player;
        players = new Player[num_player];

        for (int i = 0; i < num_player; ++i) {
            players[i].setId(i + 1);
        }

        cout << "已生成一副牌（去除大小王）！" << "（按空格进行洗牌）" << endl;
        //A.display_All_poker();
        int ch;
        while (1) {
            if (_kbhit()) {
                ch = _getch();
                if (ch == 32) {
                    for (int i = 0; i < 10; i++) {
                        A.shuffle_All_poker();
                    }
                    break;
                }
            }
        }

        cout << "已洗牌！(洗了十遍)" << "（按空格键进行发牌）" << endl;


        while (1) {
            if (_kbhit()) {
                ch = _getch();
                if (ch == 32) {
                    for (int i = 0; i < num_player; i++) {
                        cout << "玩家" << i + 1 << "的牌：\n";
                        A.deal_poker(players, i);
                        cout << "\n";
                    }
                    break;
                }
            }
        }

        int max = players[0].getSum();
        int index = 0;
        for (int i = 0; i < num_player - 1; ++i) {
            if (max < players[i + 1].getSum()) {
                max = players[i + 1].getSum();
                index = i + 1;
            } else {
                continue;
            }
        }
        cout << "玩家" << index +1<< "胜利" << endl;

        A.test(players[1],100);
        cout<<players[1].getSum()<<endl;

        cout << "请问要再玩一次吗？（是：1/否：2）" << endl;
        while (1) {
            if (_kbhit()) {
                ch = _getch();
                if (ch == 49)
                    break;
                else if (ch == 50) {
                    sign = false;
                    cout << "愿赌服输哦~ 欢迎下次再玩！" << endl;
                    break;
                }
            }
        }
    }

    system("pause");
    return 0;
}

