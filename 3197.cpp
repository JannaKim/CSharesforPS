#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int r, c;
char lake[1500][1500] = { 0 };
int swanvisit[1500][1500] = { 0 };

queue<pair<int, int>> meltingice;
queue <pair<int, int>> water;

int main()
{
	int num = 0;
	int cnt = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	pair<int, int> swan[2];

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> lake[j][i];
			if (lake[j][i] == 'L')
			{
				swan[num++] = make_pair(j, i);
				water.push({ j,i });
				lake[j][i] = '.';
			}
			else if (lake[j][i] == '.')
			{
				water.push({ j,i });
			}
		}
	}
	queue <pair<int, int>> swangoes;

	swanvisit[swan[0].first][swan[0].second] = 1;
	swangoes.push(make_pair(swan[0].first, swan[0].second));

	while (++cnt)
	{
		queue <pair<int, int>> nextswangoes;

		while (!swangoes.empty())
		{
			int hx = swangoes.front().first;
			int hy = swangoes.front().second;
			swangoes.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = hx + dx[i];
				int ny = hy + dy[i];
				if (nx >= 0 && nx < c && ny >= 0 && ny < r && !swanvisit[nx][ny])
				{
					if (lake[nx][ny] == '.')
					{
						swanvisit[nx][ny] = 1;
						swangoes.push(make_pair(nx, ny));
					}
					if (lake[nx][ny] == 'X')
					{
						swanvisit[nx][ny] = 1;
						nextswangoes.push(make_pair(nx, ny));
					}
				}
			}
			if (swanvisit[swan[1].first][swan[1].second] != 0)
			{
				cout << cnt - 1;
				return 0;
			}
		}

		swangoes = nextswangoes;

		int size = water.size();

		while (size--)
		{
			int hx = water.front().first;
			int hy = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = hx + dx[i];
				int ny = hy + dy[i];
				if (nx >= 0 && nx < c && ny >= 0 && ny < r)
				{
					if (lake[nx][ny] == 'X')
					{
						lake[nx][ny] = '.';
						water.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}