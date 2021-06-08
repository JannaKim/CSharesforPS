#include <deque>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> line[801];
int n, e, v_1, v_2;
const long long inf = 10000000000;
long long dist[801];

long long pathfinder(int start, int dest)
{
	fill(&dist[0], &dist[801], inf);

	priority_queue <pair<long long, int>> dij;

	dij.push(make_pair(0, start));
	dist[start] = 0;

	while (!dij.empty())
	{
		long long cost = -dij.top().first;
		int h = dij.top().second;

		dij.pop();

		if (dist[h] < cost)
		{
			continue;
		}

		int size = line[h].size();

		for (int i = 0; i < size; i++)
		{
			int next = line[h][i].first;
			long long nc = line[h][i].second;
			
			if (dist[next] > dist[h] + nc)
			{
				dist[next] = dist[h] + nc;
				dij.push(make_pair(-dist[next], next));
			}
		}
	}
	return dist[dest];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		line[a].push_back(make_pair(b, c));
		line[b].push_back(make_pair(a, c));
	}
	cin >> v_1 >> v_2;

	long long temp1 = pathfinder(1, v_1) + pathfinder(v_1, v_2) + pathfinder(v_2, n);
	long long temp2 = pathfinder(1, v_2) + pathfinder(v_2, v_1) + pathfinder(v_1, n);

	if (temp1 >= inf && temp2 >= inf)
	{
		cout << -1;
	}
	else if (temp1 > temp2)
	{
		cout << temp2;
	}
	else if (temp1 <= temp2)
	{
		cout << temp1;
	}
}
