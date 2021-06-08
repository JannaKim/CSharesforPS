#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

const int inf = 1000000000;

int t, n, m, w;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--)
	{
		int flag = 0;

		vector <pair<int, int>> path[501];

		cin >> n >> m >> w;

		int d[501];

		for (int i = 0; i < 501; i++)
		{
			d[i] = inf;
		}

		d[1] = 0;

		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			path[s].push_back(make_pair(e, t));
			path[e].push_back(make_pair(s, t));
		}
		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			path[s].push_back(make_pair(e, -t));
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				for (auto& a : path[j])
				{
					int next = a.first;
					int adv = a.second;
					if (i < n - 1)
					{
						if (d[j] + adv < d[next])
						{
							d[next] = d[j] + adv;
						}
					}
					else
					{
						if (d[j] + adv < d[next])
						{
							flag = 1;
						}
					}
				}
			}
		}
		if (flag == 1)
		{
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
}
