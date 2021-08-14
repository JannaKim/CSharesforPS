#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, st, dt;
const int INFI = 2147483647;
int dist[1001];

vector<pair<int, int>> line[1001];

void adventure(int start)
{
	fill(&dist[0], &dist[1001], INFI);

	priority_queue <pair<int, int>> dij;

	dij.push({ 0, start });

	dist[start] = 0;

	while (!dij.empty())
	{
		int cost = -dij.top().first;
		int here = dij.top().second;

		dij.pop();

		if (dist[here] < cost)
		{
			continue;
		}

		int size = line[here].size();

		for (int i = 0; i < size; i++)
		{
			int next = line[here][i].first;
			int nextcost = line[here][i].second;

			if (dist[next] > dist[here] + nextcost)
			{
				dist[next] = dist[here] + nextcost;
				dij.push({ -dist[next], next });
			}
		}
	}

	return;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		line[a].push_back({ b, c });
	}

	cin >> st >> dt;

	adventure(st);

	cout << dist[dt];
	return 0;
}