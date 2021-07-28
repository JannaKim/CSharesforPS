#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

struct info
{
	int x;
	int y;
	int trespassed;
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int maze[1000][1000];
int visit[2][1000][1000] = { 0 };
int n, m;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &maze[j][i]);
		}
	}

	queue <info> ham;

	ham.push({ 0, 0, 0 });
	visit[0][0][0] = 1;

	while (!ham.empty())
	{
		int hx = ham.front().x;
		int hy = ham.front().y;
		int na = ham.front().trespassed;

		if (hx == m - 1 && hy == n - 1)
		{
			cout << visit[na][hx][hy];
			return 0;
		}

		ham.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = hx + dx[i];
			int ny = hy + dy[i];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
			{
				if (!maze[nx][ny] && !visit[na][nx][ny])
				{
					visit[na][nx][ny] = visit[na][hx][hy] + 1;
					ham.push({ nx, ny , na});
				}
				else if(maze[nx][ny] && !na)
				{
					visit[1][nx][ny] = visit[na][hx][hy] + 1;
					ham.push({ nx, ny, 1 });
				}
			}
		}
	}

	cout << -1;

	return 0;
}