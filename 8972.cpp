#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int game[100][100] = { 0, };
int bot[100][100] = { 0, };
string cmd;
int r, c, na, cd, x, y, cnt, madsize, en;
int dx[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };

struct mad
{
	int x;
	int y;
	int alive;
};

vector<mad> ar;

void move()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			bot[j][i] = -1;
		}
	}
	for (int i = 0; i < madsize; i++)
	{
		if (ar[i].alive == 1)
		{
			int cx = ar[i].x;
			int cy = ar[i].y;

			game[cx][cy] = 0;

			if (x > cx)
			{
				if (y < cy)
				{
					ar[i].x -= dx[1];
					ar[i].y -= dy[1];
				}
				else if (y == cy)
				{
					ar[i].x -= dx[4];
					ar[i].y -= dy[4];
				}
				else if (y > cy)
				{
					ar[i].x -= dx[7];
					ar[i].y -= dy[7];
				}
			}
			else if (x == cx)
			{
				if (y < cy)
				{
					ar[i].x -= dx[2];
					ar[i].y -= dy[2];
				}
				else if (y > cy)
				{
					ar[i].x -= dx[8];
					ar[i].y -= dy[8];
				}
			}
			else if (x < cx)
			{
				if (y < cy)
				{
					ar[i].x -= dx[3];
					ar[i].y -= dy[3];
				}
				else if (y == cy)
				{
					ar[i].x -= dx[6];
					ar[i].y -= dy[6];
				}
				else if (y > cy)
				{
					ar[i].x -= dx[9];
					ar[i].y -= dy[9];
				}
			}
			if (ar[i].x == x && ar[i].y == y)
			{
				en = 1;
				break;
			}
			else if (bot[ar[i].x][ar[i].y] == -1)
			{
				bot[ar[i].x][ar[i].y] = i;
			}
			else if (bot[ar[i].x][ar[i].y] != -1) {
				ar[i].alive = 0;
				ar[bot[ar[i].x][ar[i].y]].alive = 0;
			}
		}
	}
	for (int i = 0; i < madsize; i++)
	{
		if (ar[i].alive == 0)
		{
			game[ar[i].x][ar[i].y] = 0;
		}
		else if (ar[i].alive == 1)
		{
			game[ar[i].x][ar[i].y] = 2;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char ch;
			cin >> ch;
			if (ch == 'R')
			{
				mad ard = { j, i, 1 };
				game[j][i] = 2;
				ar.push_back(ard);
				cd++;
			}
			else if (ch == 'I')
			{
				x = j;
				y = i;
			}
		}
	}
	cin >> cmd;

	int playtime = cmd.length();

	while (playtime--)
	{
		madsize = ar.size();
		game[x][y] = 0;
		x += dx[cmd[na] - 48];
		y += dy[cmd[na] - 48];
		cnt++;
		na++;
		if (game[x][y] == 2)
		{
			cout << "kraj " << cnt;
			return 0;
		}
		game[x][y] = 1;
		move();

		if (en == 1)
		{
			cout << "kraj " << cnt;
			return 0;
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{

			if (game[j][i] == 0)
			{
				cout << ".";
			}
			else if (game[j][i] == 1)
			{
				cout << "I";
			}
			else if (game[j][i] == 2)
			{
				cout << "R";
			}
		}
		cout << endl;
	}
}