
#include "Entity/Player.h"
#include "Entity/Poker.h"

#include <iostream>
#include <conio.h>
#include <string>


using namespace std;

int main() {
    srand(time(0));  //������������ӣ���֤�������ͬ
    int num_player;
    bool sign = true;
    cout << "��ӭ���롶ը�𻨡���Ϸ��" << endl;
    Poker A;
    Player *players;
    while (sign) {
        cout << "���������������";
        cin >> num_player;
        players = new Player[num_player];

        for (int i = 0; i < num_player; ++i) {
            players[i].setId(i + 1);
        }

        cout << "������һ���ƣ�ȥ����С������" << "�����ո����ϴ�ƣ�" << endl;
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

        cout << "��ϴ�ƣ�(ϴ��ʮ��)" << "�����ո�����з��ƣ�" << endl;


        while (1) {
            if (_kbhit()) {
                ch = _getch();
                if (ch == 32) {
                    for (int i = 0; i < num_player; i++) {
                        cout << "���" << i + 1 << "���ƣ�\n";
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
        cout << "���" << index +1<< "ʤ��" << endl;

        A.test(players[1],100);
        cout<<players[1].getSum()<<endl;

        cout << "����Ҫ����һ���𣿣��ǣ�1/��2��" << endl;
        while (1) {
            if (_kbhit()) {
                ch = _getch();
                if (ch == 49)
                    break;
                else if (ch == 50) {
                    sign = false;
                    cout << "Ը�ķ���Ŷ~ ��ӭ�´����棡" << endl;
                    break;
                }
            }
        }
    }

    system("pause");
    return 0;
}

