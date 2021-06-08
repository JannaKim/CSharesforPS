#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int r, c, k;
int cave[100][101] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '.')
			{
				cave[j][i] = 0;
			}
			else
			{
				cave[j][i] = 1;
			}
		}
	}
	for (int j = 0; j < c; j++)
	{
		cave[j][r] = 1;
	}

	cin >> k;

	queue<int> cmd;
	for (int i = 0; i < k; i++)
	{
		int height = 0;
		cin >> height;
		height = r - height;
		cmd.push(height);
	}

	for (int i = 0; i < k; i++)
	{
		int turn = i % 2;
		int height = cmd.front();
		cmd.pop();

		if (turn == 0)
		{
			for (int a = 0; a < c; a++)
			{
				if (cave[a][height] == 1)
				{
					cave[a][height] = 0;
					break;
				}
			}
		}
		else
		{
			for (int a = c - 1; a >= 0; a--)
			{
				if (cave[a][height] == 1)
				{
					cave[a][height] = 0;
					break;
				}
			}
		}
		int status[100][101] = { 0 };

		queue <pair<int, int>> ice;

		status[0][r] = 1;
		ice.push(make_pair(0, r));

		while (!ice.empty())
		{
			pair<int, int> here = ice.front();
			ice.pop();

			for (int b = 0; b < 4; b++)
			{
				int xx = here.first + dx[b];
				int yy = here.second + dy[b];

				if (xx >= 0 && xx < c && yy >= 0 && yy <= r && status[xx][yy] == 0 && cave[xx][yy] == 1)
				{
					status[xx][yy] = 1;
					ice.push(make_pair(xx, yy));
				}
			}
		}
		vector<pair<int, int>> falling;
		int hei = 999999;
		for (int l = 0; l < r; l++)
		{
			for (int j = 0; j < c; j++)
			{
				if (status[j][l] == 0 && cave[j][l] == 1)
				{
					int cnt = 0;
					falling.push_back(make_pair(j, l));

					while (1)
					{
						cnt++;
						if (cave[j][l + cnt] == 1 && status[j][l + cnt] == 1)
						{
							break;
						}
					}
					if (cnt < hei)
					{
						hei = cnt;
					}
				}
			}
		}
		int sizes = falling.size();
		for (int i = 0; i < sizes; i++)
		{
			cave[falling.back().first][falling.back().second] = 0;
			cave[falling.back().first][falling.back().second + hei - 1] = 1;
			falling.pop_back();
		}
	}
	for (int p = 0; p < r; p++)
	{
		for (int j = 0; j < c; j++)
		{
			int ch = cave[j][p];
			if (ch == 0)
			{
				cout << '.';
			}
			else
			{
				cout << 'x';
			}
		}
		cout << '\n';
	}
}
