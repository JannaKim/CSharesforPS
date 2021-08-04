#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info
{
	int x;
	int y;
	int cont_num;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n;
int dist = 9999;
int mapleworld[100][100] = { 0 };
int visit[100][100] = { 0 };

vector <info> point;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mapleworld[j][i];
		}
	}

	int num = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mapleworld[j][i] == 1 && !visit[j][i])
			{
				queue <pair<int, int>> adventurer;

				adventurer.push({ j, i });
				visit[j][i] = 1;
				mapleworld[j][i] = num;

				while (!adventurer.empty())
				{
					int hx = adventurer.front().first;
					int hy = adventurer.front().second;

					adventurer.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = hx + dx[k];
						int ny = hy + dy[k];

						if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny])
						{
							if (mapleworld[nx][ny] == 1)
							{
								mapleworld[nx][ny] = num;
								adventurer.push({ nx, ny });
								visit[nx][ny] = 1;
							}
							else
							{
								point.push_back({ nx, ny, num });
							}
						}
					}
				}
				num++;
			}
		}
	}

	num = 0;
	
	while (num < point.size())
	{
		int flag = 0;
		fill(&visit[0][0], &visit[99][100], 0);

		queue <pair<int, int>> adventurer;

		adventurer.push({ point[num].x , point[num].y });

		visit[point[num].x][point[num].y] = 1;

		while (!adventurer.empty())
		{
			int hx = adventurer.front().first;
			int hy = adventurer.front().second;

			adventurer.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = hx + dx[k];
				int ny = hy + dy[k];

				if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny])
				{
					if (mapleworld[nx][ny] == 0)
					{
						adventurer.push({ nx, ny });
						visit[nx][ny] = visit[hx][hy] + 1;
					}
					else if(point[num].cont_num != mapleworld[nx][ny])
					{
						dist = min(dist, visit[hx][hy]);
						flag = 1;
						break;
					}
				}
			}
			if (flag)
			{
				break;
			}
		}
		num++;
	}

	cout << dist;
	return 0;
}