#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int castle[50][50];
int visit[50][50] = { 0 };
int n, m;
int lgst_Spc = 0;
int brk_Lgst_Spc = 0;
int room = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> castle[j][i];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[j][i])
			{
				int temp = 1;
				room++;
				queue <pair<int, int>> bfs;

				bfs.push({ j, i });
				visit[j][i] = 1;

				while (!bfs.empty())
				{
					int hx = bfs.front().first;
					int hy = bfs.front().second;

					bfs.pop();

					for (int k = 0; k < 4; k++)
					{
						int nx = hx + dx[k];
						int ny = hy + dy[k];

						if (nx >= 0 && ny >= 0 && nx < n && ny < m)
						{
							if ((castle[hx][hy] & (1 << k)) || visit[nx][ny])
							{
								continue;
							}
							visit[nx][ny] = 1;
							bfs.push({ nx, ny });
							temp++;
						}
					}
				}
				lgst_Spc = max(temp, lgst_Spc);
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 1; k <= 8; k *= 2)
			{
				if (castle[j][i] & k)
				{
					castle[j][i] -= k;
					int temp = 1;
					int visited[50][50] = { 0 };

					queue <pair<int, int>> bfs;

					bfs.push({ j, i });
					visited[j][i] = 1;

					while (!bfs.empty())
					{
						int hx = bfs.front().first;
						int hy = bfs.front().second;

						bfs.pop();

						for (int k = 0; k < 4; k++)
						{
							int nx = hx + dx[k];
							int ny = hy + dy[k];

							if (nx >= 0 && ny >= 0 && nx < n && ny < m)
							{
								if ((castle[hx][hy] & (1 << k)) || visited[nx][ny])
								{
									continue;
								}
								visited[nx][ny] = 1;
								bfs.push({ nx, ny });
								temp++;
							}
						}
					}
					brk_Lgst_Spc = max(brk_Lgst_Spc, temp);
					castle[j][i] += k;
				}
			}
		}
	}

	cout << room << '\n' << lgst_Spc << '\n' << brk_Lgst_Spc;

	return 0;
}