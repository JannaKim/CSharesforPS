#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
long long dist[1001] = { 0 };
int connected[1001] = { 0 };
long long inf = 100000000;

vector<pair<int, int>> path[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	fill(&dist[0], &dist[1001], inf);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		path[a].push_back(make_pair(b, c));
		path[b].push_back(make_pair(a, c));
	}
	priority_queue <pair<int, int>> dij;
	dist[1] = 0;
	dij.push(make_pair(0, 1));
	while (!dij.empty())
	{
		int h = dij.top().second;

		dij.pop();

		int size = path[h].size();

		for (int i = 0; i < size; i++)
		{
			int next = path[h][i].first;
			int lapse = path[h][i].second;

			if (dist[h] + lapse < dist[next])
			{
				dist[next] = dist[h] + lapse;
				connected[next] = h;
				dij.push(make_pair(-dist[next], next));
			}
		}
	}

	queue<int> temp;
	
	for (int i = 1; i <= n; i++)
	{
		if (connected[i] != 0)
		{
			temp.push(i);
		}
	}
	int cnt = temp.size();
	cout << cnt << "\n";

	for (int i = 0; i < cnt; i++)
	{
		int num = temp.front();
		temp.pop();
		cout << connected[num] << " " << num << "\n";
	}
}