#ifndef GameRecord_
#define GameRecord_
#include <iostream>
#include <string>
#include "rlutil.h"
using namespace std;

struct node
{
    string player_1;
    string player_2;
    int score_1;
    int score_2;
    node *next;
};

class GameRecord
{
public:
    GameRecord()
    {
        first = nullptr;
    }
    ~GameRecord()
    {
        delete first;
    }
    bool isEmpty()
    {
        return first == nullptr;
    }
    void addGame(string p1, string p2, int s1, int s2);
    void print();

private:
    node *first;
};

#endif // GameRecord_