#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, k;

struct mal
{
	int x;
	int y;
	int dir;
};

deque <int> status[12][12];
vector <mal> mark;

int game[12][12];
int change_dir(int i)
{
	int dir;
	if (i < 2)
	{
		dir = i == 0 ? 1 : 0;
	}
	else
	{
		dir = i == 2 ? 3 : 2;
	}
	return dir;
}
int main()
{
	int round = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> game[j][i];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int x, y, direction;
		cin >> y >> x >> direction;

		status[x - 1][y - 1].push_back(i);
		mark.push_back({ x - 1, y - 1, direction - 1 });
	}

	while (1)
	{
		for (int i = 0; i < k; i++)
		{
			int d = mark[i].dir;
			int hx = mark[i].x;
			int hy = mark[i].y;

			int nx = hx + dx[d];
			int ny = hy + dy[d];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n || game[nx][ny] == 2)
			{
				d = change_dir(d);
				mark[i].dir = d;
				nx = hx + dx[d];
				ny = hy + dy[d];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || game[nx][ny] == 2)
				{
					continue;
				}
			}
			if (game[nx][ny] == 0)
			{
				vector <int> temp;
				while (1)
				{
					int a = status[hx][hy].back();
					status[hx][hy].pop_back();
					temp.push_back(a);
					if (a == i)
					{
						break;
					}
				}
				while (!temp.empty())
				{
					int a = temp.back();
					temp.pop_back();
					status[nx][ny].push_back(a);

					mark[a].x = nx;
					mark[a].y = ny;
				}
			}
			else if (game[nx][ny] == 1)
			{
				while (1)
				{
					int a = status[hx][hy].back();
					status[hx][hy].pop_back();
					status[nx][ny].push_back(a);

					mark[a].x = nx;
					mark[a].y = ny;
					if (a == i)
					{
						break;
					}
				}
			}
			if (status[nx][ny].size() >= 4)
			{
				cout << round;
				return 0;
			}
		}
		if (round > 1000)
		{
			cout << -1;
			return 0;
		}
		round++;
	}
}