//
// Created by Administrator on 2022/7/10.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
private:int id;
public:int* num;
public:
    int *getNum() const;

    void setNum(int *num);

public:
    int sum;
public:
    int getSum() const;

    void setSum(int sum);

public:
    virtual ~Player();

public:
    Player();

    int getId() const;

    void setId(int id);


};
#endif //ZHAJINHUA_PLAYER_H
