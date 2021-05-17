#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;
char board[20][20];
int alp[26] = { 0, };
int r, c;
int m;

void dfs(int x, int y, int cnt)
{
	if (m < cnt)
	{
		m = cnt;
	}

	if(y > 0 && alp[board[x][y - 1] - 65] == 0) // À§·Î
	{
		alp[board[x][y - 1] - 65] = 1;
		dfs(x, y - 1, cnt + 1);
		alp[board[x][y - 1] - 65] = 0;
	}
	if (y < r - 1 && alp[board[x][y + 1] - 65] == 0)
	{
		alp[board[x][y + 1] - 65] = 1;
		dfs(x, y + 1, cnt + 1);
		alp[board[x][y + 1] - 65] = 0;
	}
	if (x > 0 && alp[board[x - 1][y] - 65] == 0)
	{
		alp[board[x - 1][y] - 65] = 1;
		dfs(x - 1, y, cnt + 1);
		alp[board[x - 1][y] - 65] = 0;
	}
	if (x < c - 1 && alp[board[x + 1][y] - 65] == 0)
	{
		alp[board[x + 1][y] - 65] = 1;
		dfs(x + 1, y, cnt + 1);
		alp[board[x + 1][y] - 65] = 0;
	}
	return;
}

int main()
{
	m = 0;

	scanf("%d", &r);
	scanf("%d", &c);

	getchar();

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%c", &board[j][i]);
		}
		getchar();
	}

	alp[board[0][0] - 65] = 1;
	dfs(0, 0, 1);

	printf("%d", m);
}