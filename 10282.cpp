#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

const long long inf = 10000000000;
int t;
using namespace std;

pair<int, int> Wanna_Cry(int n, int d, int c)
{
	int max = 0;
	priority_queue <pair<int, int>> pq;
	long long dist[10001];
	vector <pair<int, int>> cmd[10001];
	for (int i = 0; i < d; i++)
	{
		int s, e, t;
		cin >> e >> s >> t;
		cmd[s].push_back(make_pair(e, t));
	}

	fill(&dist[0], &dist[10001], inf);

	pq.push(make_pair(0, c));

	dist[c] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		for (int i = 0; i < cmd[here].size(); i++)
		{
			int next = cmd[here][i].first;
			int nextcost = cost + cmd[here][i].second;
			
			if (nextcost < dist[next])
			{
				dist[next] = nextcost;
				pq.push({ -dist[next], next});
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] != inf)
		{
			cnt++;
		}
		if (max < dist[i] && dist[i] != inf)
		{
			max = dist[i];
		}
	}
	return make_pair(cnt, max);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		pair<int, int> ans;
		int n, d, c;
		cin >> n >> d >> c;
		ans = Wanna_Cry(n, d, c);
		cout << ans.first << " " << ans.second << "\n";
	}
}