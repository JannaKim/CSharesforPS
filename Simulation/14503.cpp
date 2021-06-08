#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int house[53][53];
int n, m, r, c, d, cnt;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int x, y;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cnt = 0;
	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> house[i][j];
		}
	}
	while (1)
	{
		int flag = 0;
		if (house[x][y] == 0)
		{
			house[x][y] = 2;
			cnt++;
		}

		for (int i = 0; i < 4; i++)
		{
			d--;
			if (d < 0)
			{
				d = 3;
			}
			int ix = x + dx[d];
			int iy = y + dy[d];

			if (house[ix][iy] == 0)
			{
				x = ix;
				y = iy;
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			int ix = x - dx[d];
			int iy = y - dy[d];

			if (house[ix][iy] != 1)
			{
				x = ix;
				y = iy;
				continue;
			}
			else
			{
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
