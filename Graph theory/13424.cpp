#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, n, m, k;
int dist[101][101];
const int mugen = 214855055;

void dijk(int member, int start, vector<pair<int, int>> path[101])
{
	priority_queue <pair<long long, int>> dij;

	dij.push(make_pair(0, start));

	dist[member][start] = 0;

	while (!dij.empty())
	{
		int cost = -dij.top().first;
		int h = dij.top().second;

		dij.pop();

		if (dist[member][h] < cost)
		{
			continue;
		}

		int size = path[h].size();

		for (int i = 0; i < size; i++)
		{
			int next = path[h][i].first;
			long long nc = path[h][i].second;

			if (dist[member][next] > dist[member][h] + nc)
			{
				dist[member][next] = dist[member][h] + nc;
				dij.push(make_pair(-dist[member][next], next));
			}
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		fill(&dist[0][0], &dist[99][101], mugen);
		
		vector <pair<int, int>> path[101];

		cin >> n >> m;

		for (int j = 0; j < m; j++)
		{
			int a, b, c;

			cin >> a >> b >> c;

			path[a].push_back({ b, c });
			path[b].push_back({ a, c });
		}

		cin >> k;

		for (int f = 0; f < k; f++)
		{
			int h;

			cin >> h;

			dijk(f, h, path);
		}

		int ans = mugen;
		int num = 0;

		for (int j = n; j > 0; j--)
		{
			dist[100][j] = 0;
			for (int fri = 0; fri < k; fri++)
			{
				if (dist[fri][j] >= mugen)
				{
					dist[100][j] += dist[fri][j];
					break;
				}

				dist[100][j] += dist[fri][j];
			}
			if (ans >= dist[100][j])
			{
				ans = dist[100][j];
				num = j;
			}
		}
		cout << num << endl;
	}
	return 0;
}