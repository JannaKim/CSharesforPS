#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int combo = 0, cnt;
char puyo[6][12];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector <pair<int, int>> beads;

int gravity_falls()
{
	int flag = 0;
	for (int i = 11; i >= 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			if (puyo[j][i] != '.' && puyo[j][i + 1] == '.' && i < 11)
			{
				int below = 1;
				flag = 1;
				while (1)
				{
					if (puyo[j][i + below + 1] == '.' && i + below < 11)
					{
						below++;
					}
					else
					{
						break;
					}
				}
				puyo[j][i + below] = puyo[j][i];
				beads.push_back({ j, i + below });
				puyo[j][i] = '.';
			}
			else if (puyo[j][i] != '.')
			{
				beads.push_back({ j, i });
			}
		}
	}
	return flag;
}

int main()
{
	int flag = 0;
	int end = 1;

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> puyo[j][i];
			if (puyo[j][i] != '.')
			{
				beads.push_back({ j,i });
			}
		}
	}
	while (end)
	{
		int visit[6][12] = { 0 };
		flag = 0;
		while (!beads.empty())
		{
			int j = beads.back().first;
			int i = beads.back().second;

			beads.pop_back();

			if (puyo[j][i] != '.' && !visit[j][i])
			{
				cnt = 1;
				queue <pair<int, int>> bubble;
				vector <pair<int, int>> temp;
				bubble.push({ j, i });
				temp.push_back({ j, i });
				visit[j][i] = 1;
				while (!bubble.empty())
				{
					int hx = bubble.front().first;
					int hy = bubble.front().second;

					bubble.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = hx + dx[k];
						int ny = hy + dy[k];

						if (nx >= 0 && nx < 6 && ny >= 0 && ny < 12 && puyo[j][i] == puyo[nx][ny] && !visit[nx][ny])
						{
							cnt++;
							visit[nx][ny] = 1;
							temp.push_back({ nx, ny });
							bubble.push({ nx, ny });
						}
					}
				}
				if (cnt >= 4)
				{
					flag = 1;
					while (!temp.empty())
					{
						puyo[temp.back().first][temp.back().second] = '.';
						temp.pop_back();
					}
				}
			}
		}
		end = gravity_falls();
		if (flag == 1)
		{
			combo++;
		}
	}
	cout << combo;
	return 0;
}