#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, lowest = 101, highest = -1, maxs = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = {  0, -1, 0, 1 };
int ground[100][100] = { 0, };

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ground[j][i];

			if (ground[j][i] < lowest)
			{
				lowest = ground[j][i];
			}
			if (ground[j][i] > highest)
			{
				highest = ground[j][i];
			}
		}
	}
	for (int level = lowest - 1; level <= highest; level++)
	{
		int cnt = 0;
		int visit[100][100] = { 0, };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (ground[j][i] > level && visit[j][i] == 0)
				{
					queue<pair<int, int>> q;
					visit[j][i] = 1;
					q.push(make_pair(j, i));
					cnt++;
					while (!q.empty())
					{
						pair<int, int> now = q.front();
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							int nx = now.first + dx[k];
							int ny = now.second + dy[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < n)
							{
								if (ground[nx][ny] > level && visit[nx][ny] == 0)
								{
									visit[nx][ny] = 1;
									q.push(make_pair(nx, ny));
								}
							}
						}
					}
				}
			}
		}
		if (maxs < cnt)
		{
			maxs = cnt;
		}
	}
	cout << maxs;
	return 0;
}