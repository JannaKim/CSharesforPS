#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <set>
#include <math.h>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int board[5][5];

set<int> m;

int a = 0;

void dfs(int x, int y, int cnt, int sum)
{
	if (cnt == 5)
	{
		m.insert(sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (yy >= 0 && yy < 5 && xx >= 0 && xx < 5)
		{
			dfs(xx, yy, cnt + 1, sum * 10 + board[xx][yy]);
		}
	}
}

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

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(j, i, 0, board[j][i]);
		}
	}
	cout << m.size() << endl;
	return 0;
}