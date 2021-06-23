#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dice[7] = { 0 };
int map[20][20];
int cmd[1000];

int n, m, x, y, k;

void roll(int dir)
{
	int temp[7];
	for (int i = 1; i < 7; i++)
	{
		temp[i] = dice[i];
	}
	if (dir == 1)
	{
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (dir == 2)
	{
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[6] = temp[4];
		dice[4] = temp[1];
	}
	else if (dir == 3)
	{
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
	}
	else
	{
		dice[5] = temp[1];
		dice[6] = temp[5];
		dice[2] = temp[6];
		dice[1] = temp[2];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> y >> x >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[j][i];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> cmd[i];
	}

	for (int i = 0; i < k; i++)
	{
		int nx = x + dx[cmd[i] - 1];
		int ny = y + dy[cmd[i] - 1];

		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		{
			continue;
		}

		roll(cmd[i]);

		x = nx;
		y = ny;

		if (map[nx][ny] == 0)
		{
			map[nx][ny] = dice[6];
		}
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[1] << '\n';
	}
	return 0;
}