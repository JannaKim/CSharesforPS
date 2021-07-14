#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int n, q;
int a[64][64];
int cmd[1000];
int sum = 0, bergSize = 0;
int visit[64][64] = { 0 };

void rotate(int x, int y, int length)
{
	int temp[64][64];

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			temp[i][j] = a[x + j][y + i];
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			a[x - j + length - 1][y + i] = temp[j][i];
		}
	}
	return;
}

void chooseRegion(int length)
{
	for (int i = 0; i < (1 << n); i += (1 << length))
	{
		for (int j = 0; j < (1 << n); j += (1 << length))
		{
			rotate(j, i, 1 << length);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> q;

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			cin >> a[j][i];
		}
	}

	for (int i = 0; i < q; i++)
	{
		cin >> cmd[i];
	}

	for (int i = 0; i < q; i++)
	{
		queue <pair<int, int>> command;

		chooseRegion(cmd[i]);
		for (int i = 0; i < (1 << n); i++)
		{
			for (int j = 0; j < (1 << n); j++)
			{
				if (a[j][i] > 0)
				{
					int cnt = 0;
					for (int k = 0; k < 4; k++)
					{
						int x = j + dx[k];
						int y = i + dy[k];
						if (x >= 0 && y >= 0 && x < (1 << n) && y < (1 << n))
						{
							if (a[x][y] != 0)
							{
								cnt++;
							}
						}
					}
					if (cnt < 3)
					{
						command.push({ j, i });
					}
				}
			}
		}
		if (command.size() != 0)
		{
			while (!command.empty())
			{
				int x = command.front().first;
				int y = command.front().second;

				command.pop();

				a[x][y] -= 1;
			}
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			int temp = 0;
			if (!visit[j][i] && a[j][i] != 0)
			{
				queue <pair<int, int>> bfs;

				bfs.push({ j, i });
				visit[j][i] = 1;
				sum += a[j][i];
				temp++;

				while (!bfs.empty())
				{
					int hx = bfs.front().first;
					int hy = bfs.front().second;

					bfs.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = hx + dx[k];
						int ny = hy + dy[k];

						if (nx >= 0 && ny >= 0 && nx < (1 << n) && ny < (1 << n) && a[nx][ny] != 0 && !visit[nx][ny])
						{
							visit[nx][ny] = 1;
							bfs.push({ nx, ny });
							sum += a[nx][ny];
							temp++;
						}
					}
				}
				bergSize = max(temp, bergSize);
			}
		}
	}

	cout << sum << '\n' << bergSize;
	return 0;
}