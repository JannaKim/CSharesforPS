#include <deque>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<int, int> d[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int a[50][50];
int n, l, r;
int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[j][i];
		}
	}

	while (1)
	{
		int flag = 0;
		int visit[50][50] = { 0 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visit[j][i])
				{
					continue;
				}
				int sum = a[j][i];
				queue <pair<int, int>> disperse;
				vector <pair<int, int>> equalize;
				visit[j][i] = 1;
				disperse.push(make_pair(j, i));
				equalize.push_back(make_pair(j, i));
				while (!disperse.empty())
				{
					pair<int, int> coor = disperse.front();
					disperse.pop();
					for (int k = 0; k < 4; k++)
					{
						int x = coor.first + d[k].first;
						int y = coor.second + d[k].second;
						if (x >= 0 && x < n && y >= 0 && y < n && !visit[x][y] && abs(a[x][y] - a[coor.first][coor.second]) >= l && abs(a[x][y] - a[coor.first][coor.second]) <= r)
						{
							visit[x][y] = 1;
							sum += a[x][y];
							disperse.push(make_pair(x, y));
							equalize.push_back(make_pair(x, y));
						}
					}
				}
				if (equalize.size() > 1)
				{
					flag = 1;
				}
				if (equalize.size() != 0)
				{
					sum /= equalize.size();
					while (!equalize.empty())
					{
						int x = equalize.back().first;
						int y = equalize.back().second;

						equalize.pop_back();

						a[x][y] = sum;
					}
				}
			}
		}
		if (flag == 0)
		{
			break;
		}
		cnt++;
	}
	cout << cnt;
}