#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };

int w[501][10001];
int v[501][10001];
int swi = 0;
int r, c;
int dfs(int x, int y)
{
	if (x == c - 1 && swi == 0)
	{
		swi = 1;
		return 1;
	}

	for (int i = 0; i < 3; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (yy >= 0 && yy < r && xx >= 0 && xx < c && v[xx][yy] == 0 && w[xx][yy] == 0)
		{
			v[xx][yy] = 1;
			dfs(xx, yy);
			if (swi == 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int cn = 0;
	char ch = { 0 };

	cin >> r >> c;


	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> ch;
			if (ch == '.')
			{
				w[j][i] = 0;
			}
			else
			{
				w[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		swi = 0;
		if (dfs(0, i))
		{
			cn++;
		}
	}
	printf("%d", cn);
}