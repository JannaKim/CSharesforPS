#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bamground[100][100];

deque <pair<int, int>> snake;
queue <pair<int, int>> cmd;
deque <int> direction;

int n, k, l;

int turn(char dir, int now)
{
	if (dir == 'L')
	{
		now--;
		if (now < 0)
		{
			now = 3;
		}
	}
	else
	{
		now++;
		if (now > 3)
		{
			now = 0;
		}
	}
	return now;
}

int main()
{
	int sec = 0, index = 0, now = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	snake.push_back({ 0, 0 });
	bamground[0][0] = -1;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x;
		bamground[x - 1][y - 1] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++)
	{
		int lapse;
		char dir;
		cin >> lapse >> dir;
		cmd.push({ lapse, dir });
	}
	while (1)
	{
		sec++;
		int hx  = snake.front().first;
		int hy  = snake.front().second;

		int nx = hx + dx[now];
		int ny = hy + dy[now];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && bamground[nx][ny] != -1)
		{
			if (bamground[nx][ny] == 0)
			{
				bamground[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}
			snake.push_front({ nx, ny });
			bamground[nx][ny] = -1;
		}
		else
		{
			cout << sec;
			return 0;
		}
		if (!cmd.empty() && cmd.front().first == sec)
		{
			now = turn(cmd.front().second, now);
			cmd.pop();
		}
	}
	return 0;
}