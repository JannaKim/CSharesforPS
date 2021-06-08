#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

struct loc
{
	int x;
	int y;
	int key;
	int cnt;
};

char mapleworld[50][50] = { 0 };
int visit[50][50][64];

using namespace std;

int n, m;
pair<int, int> depart;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mapleworld[j][i];
			if (mapleworld[j][i] == '0')
			{
				mapleworld[j][i] = '.';
				depart = make_pair(j, i);
			}
		}
	}
	queue <loc> go;
	visit[depart.first][depart.second][0] = 1;
	go.push({ depart.first, depart.second, 0, 0 });

	while (!go.empty())
	{
		int x = go.front().x;
		int y = go.front().y;
		int keystatus = go.front().key;
		int c = go.front().cnt;
		go.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && xx < m && yy >= 0 && yy < n && mapleworld[xx][yy] != '#' && visit[xx][yy][keystatus] == 0)
			{
				if (mapleworld[xx][yy] == '.')
				{
					visit[xx][yy][keystatus] = 1;
					go.push({ xx, yy, keystatus, c + 1 });
				}
				else if (mapleworld[xx][yy] >= 'a' && mapleworld[xx][yy] <= 'f')
				{
					int temp = keystatus | (int)pow(2, (mapleworld[xx][yy] - 'a'));
					visit[xx][yy][temp] = 1;
					go.push({ xx, yy, temp, c + 1 });
				}
				else if (mapleworld[xx][yy] >= 'A' && mapleworld[xx][yy] <= 'F')
				{
					if ((keystatus & (int)pow(2, mapleworld[xx][yy] - 'A')) == (int)pow(2, mapleworld[xx][yy] - 'A'))
					{
						visit[xx][yy][keystatus] = 1;
						go.push({ xx, yy, keystatus, c + 1 });
					}
				}
				else if (mapleworld[xx][yy] == '1')
				{
					visit[xx][yy][keystatus] = 1;
					cout << c + 1;
					return 0;
				}
			}
		}
	}
	cout << -1;
}
