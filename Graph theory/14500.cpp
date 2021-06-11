#include <deque>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
int box[500][500] = { 0 };
int visit[500][500] = { 0 };
int maxs = 0;
int maxx = 0;
int temp = 0;

void tetromino_dfs(int x, int y, int cnt, int sum)
{
	if (cnt == 3)
	{
		if (temp < sum)
		{
			temp = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n && visit[nx][ny] == 0)
		{
			visit[nx][ny] = 1;
			tetromino_dfs(nx, ny, cnt + 1, sum + box[nx][ny]);
			visit[nx][ny] = 0;
		}
	}
}

int deco1(int x, int y)
{
	int te1 = 0;
	int te2 = 0;
	if (x < m - 1 && y < n - 2)
	{
		te1 = box[x][y + 1] + box[x + 1][y] + box[x + 1][y + 1] + box[x + 1][y + 2];
		te2 = box[x + 1][y + 1] + box[x][y] + box[x][y + 1] + box[x][y + 2];
	}
	if (te1 > te2)
	{
		return te1;
	}
	else
	{
		return te2;
	}
}

int deco2(int x, int y)
{
	int te1 = 0;
	int te2 = 0;
	if (x < m - 2 && y < n - 1)
	{
		te1 = box[x + 1][y] + box[x][y + 1] + box[x + 1][y + 1] + box[x + 2][y + 1];
		te2 = box[x + 1][y + 1] + box[x][y] + box[x + 1][y] + box[x + 2][y];
	}
	if (te1 > te2)
	{
		return te1;
	}
	else
	{
		return te2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[j][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int te1 = 0;
			int te2 = 0;
			visit[j][i] = 1;
			tetromino_dfs(j, i, 0, box[j][i]);
			te1 = deco1(j , i);
			te2 = deco2(j , i);
			visit[j][i] = 0;
			if (maxx < temp)
			{
				maxx = temp;
			}
			if (te1 > te2)
			{
				temp = te1;
			}
			else
			{
				temp = te2;
			}
			if (maxx < temp)
			{
				maxx = temp;
			}
		}
	}
	cout << maxx;
}