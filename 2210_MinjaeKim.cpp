#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int board[5][5];

int main()
{
   int num = 0, cnt = 0;
   for (int i = 0; i < 5; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         cin >> board[j][i];
      }
   }
}