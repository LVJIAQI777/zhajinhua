#include "Random_f.h"
#include <cstdlib>

//生成一个随机数列表
int* random_list(int list_num)
{
    int* poker_list = new int[list_num];
    for (int i = 0; i < list_num; i++)
    {
        poker_list[i] = 100;
    }
    for (int i = 0; i < list_num; i++)
    {
        int a = 0, b = 52;
        bool sign = true;
        while (sign)
        {
            int num = (rand() % (b - a)) + a;  //产生[0,52)之间随机数
            for (int j = 0; j < list_num; j++)
            {
                if (num == poker_list[j])
                    break;
                else if(j<list_num-1)
                    continue;
                else
                {
                    poker_list[i] = num;
                    sign = false;
                }
            }

        }

    }

    return poker_list;
}