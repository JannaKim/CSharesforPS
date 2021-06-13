#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, cnt = 0;
int arctic[300][300];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

queue <pair<int, int>> iceberg;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arctic[j][i];
		}
	}

	while (++cnt)
	{
		int visit[300][300] = { 0 };
		int melt[300][300] = { 0 };
		int divided = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visit[j][i] && arctic[j][i] > 0)
				{
					divided++;
					if (divided == 2)
					{
						cout << cnt - 1;
						return 0;
					}
					visit[j][i] = 1;
					iceberg.push(make_pair(j, i));
					while (!iceberg.empty())
					{
						int hx = iceberg.front().first;
						int hy = iceberg.front().second;
						iceberg.pop();

						for (int k = 0; k < 4; k++)
						{
							int nx = hx + dx[k];
							int ny = hy + dy[k];

							if (arctic[nx][ny] > 0 && !visit[nx][ny])
							{

								visit[nx][ny] = 1;
								iceberg.push(make_pair(nx, ny));
							}
							if (arctic[nx][ny] == 0)
							{
								melt[hx][hy]++;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arctic[j][i] - melt[j][i] >= 0)
				{
					arctic[j][i] -= melt[j][i];
				}
				else
				{
					arctic[j][i] = 0;
				}
			}
		}
		if (divided == 0)
		{
			cout << 0;
			return 0;
		}
	}
}