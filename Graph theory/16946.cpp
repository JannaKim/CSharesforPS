#define _CRT_SECURE_NO_WARNINGS

#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[1000][1000] = { 0 };
int visit[1000][1000] = { 0 };
pair<int, int> noname[1000][1000];
int n, m, sum = 0, cnt = 1;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int region_num = 0;
queue<pair<int, int>> block;

void dfs(int x, int y)
{
	block.push(make_pair(x, y));
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (yy >= 0 && yy < n && xx >= 0 && xx < m)
		{
			if (!visit[xx][yy] && board[xx][yy] == 0)
			{
				cnt++;
				dfs(xx, yy);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &board[j][i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[j][i] == 0)
			{
				cnt = 1;
				dfs(j, i);
				while (!block.empty())
				{
					if (noname[block.front().first][block.front().second].first < cnt)
					{
						noname[block.front().first][block.front().second] = make_pair(cnt, region_num);
					}
					block.pop();
				}
				region_num++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a = 1;
			vector <int> rnum;
			for (int k = 0; k < 4; k++)
			{
				int xx = j + dx[k];
				int yy = i + dy[k];
				int reg = noname[xx][yy].second;
				if (yy >= 0 && yy < n && xx >= 0 && xx < m && board[xx][yy] == 0)
				{
					int flag = 0;
					for (int b = 0; b < rnum.size(); b++)
					{
						if (rnum[b] == reg)
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						a += noname[xx][yy].first;
						rnum.push_back(reg);
					}
				}
			}
			if (board[j][i] == 1)
			{
				printf("%d", a % 10);
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}
}
