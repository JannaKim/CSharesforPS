#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

const long long inf = -10000000000;

int n, m, start, dest;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long money[100] = { 0 };
	int earn[100] = { 0 };

	vector <pair<int, int>> path[100];

	cin >> n >> start >> dest >> m;

	fill(money, money + n, inf);

	for (int i = 0; i < m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		path[s].push_back(make_pair(e, t));
	}

	for (int i = 0; i < n; i++)
	{
		cin >> earn[i];
	}
	money[start] = earn[start];
	vector <int> cycle;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (auto& a : path[j])
			{
				int next = a.first;
				int adv = -a.second + earn[next];

				if (money[j] != inf && money[j] + adv > money[next])
				{
					money[next] = money[j] + adv;
					if (i == n - 1)
					{
						cycle.push_back(next);
					}
				}
			}
		}
	}
	if (money[dest] == inf)
	{
		cout << "gg";
		return 0;
	}
	while (!cycle.empty())
	{
		int visited[100] = { 0 };
		int st = cycle.back();
		cycle.pop_back();
		queue<int> bfs;
		bfs.push(st);
		while (!bfs.empty())
		{
			int dep = bfs.front();
			visited[dep] = 1;
			bfs.pop();

			for (auto& a : path[dep])
			{
				if (a.first == dest)
				{
					cout << "Gee";
					return 0;
				}
				if (visited[a.first] == 0)
				{
					visited[a.first] = 1;
					bfs.push(a.first);
				}
			}
		}
	}
	cout << money[dest];
	return 0;
}