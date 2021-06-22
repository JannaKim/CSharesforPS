#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int n, m, d, maxk = 0, kill = 0;

int field[15][16];

int dx[3] = { -1, 0, 1 };
int dy[3] = { 0, -1, 0 };

vector <int> archer;

void play()
{
	kill = 0;
	int vr[15][16];

	memcpy(vr, field, sizeof(field));

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			queue <pair<int, int>> search;

			int visit[15][15] = { 0 };
			int x = archer[i];
			int y = n;
			int flag = 0;
			search.push({ x, y });
			while (!search.empty())
			{
				int hx = search.front().first;
				int hy = search.front().second;

				search.pop();

				for (int a = 0; a < 3; a++)
				{
					int nx = hx + dx[a];
					int ny = hy + dy[a];
					
					if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny])
					{
						if (abs(nx - x) + abs(y - ny) <= d)
						{
							if (vr[nx][ny] >= 1)
							{
								vr[nx][ny]++;
								flag = 1;
								break;
							}
						}
						visit[nx][ny] = 1;
						search.push({ nx, ny });
					}
				}
				if (flag == 1)
				{
					break;
				}
			}

		}
		int f = 0;

		for (int i = n; i > 0; i--)
		{
			for (int j = 0; j < m; j++)
			{
				if (vr[j][i - 1] > 1)
				{
					
					kill++;
					vr[j][i - 1] = 0;
				}

				if (vr[j][i - 1] == 1)
				{
					vr[j][i] = vr[j][i - 1];
					vr[j][i - 1] = 0;
					f = 1;
				}
			}
		}
		if (f == 0)
		{
			break;
		}
	}
}

void dfs(int x, int cnt)
{
	
	if (cnt == 3)
	{
		play();
		if (maxk < kill)
		{
			maxk = kill;
		}
		return;
	}
	if (x == m)
	{
		return;
	}

	archer.push_back(x);
	dfs(x + 1, cnt + 1);

	archer.pop_back();
	dfs(x + 1, cnt);
}

int main()
{
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> field[j][i];
		}
	}

	dfs(0, 0);

	cout << maxk;

    return 0;
}