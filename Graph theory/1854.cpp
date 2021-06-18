#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long inf = 1234567890;
int n, m, k;
int dist[1001];
int ans;

priority_queue <pair<int, int>> pq;
priority_queue <int> vortex[1001];
vector <pair<int, int>> path[1001];

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		path[s].push_back(make_pair(e, t));
	}

	fill(&dist[0], &dist[n + 1], inf);

	pq.push({ 0, 1 });

	dist[1] = 0;

	vortex[1].push(0);

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < path[here].size(); i++)
		{
			int next = path[here][i].first;
			int nextcost = cost + path[here][i].second;
			if (vortex[next].size() < k)
			{
				vortex[next].push(nextcost);
				pq.push({ -nextcost, next });
			}
			else if (vortex[next].top() > nextcost)
			{
				vortex[next].pop();
				vortex[next].push(nextcost);
				pq.push({ -nextcost, next });
			}
			
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (vortex[i].size() < k)
		{
			cout << -1 << '\n';
			continue;
		}
		else
		{
			cout << vortex[i].top() << '\n';
		}
	}
    return 0;
}