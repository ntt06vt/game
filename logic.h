#ifndef _LOGIC__H
#define _LOGIC__H
#include<ctime>
#include <cstdlib>
#include <iostream>
#include<algorithm>
using namespace std;
struct Game {
    int board[4][4];
    void mix()
    {
         srand(time(0));
    for(int m=1;m<=100;m++)
    {
        int nn1 =   rand() % 4;
        int nn2 =   rand() % 4;
        int nn3 =   rand() % 4;
        int nn4 =   rand() % 4;
        swap(board[nn1][nn2],board[nn3][nn4]);
    }
    }
};

#endif


