#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

const long long inf = 100000000000;
long long d[501];
int n, m, flag = 0;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <pair<int, int>> path[501];

	cin >> n >> m;

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
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (auto& a : path[j])
			{
				int next = a.first;
				int adv = a.second;

				if (d[j] != inf && d[j] + adv < d[next])
				{
					d[next] = d[j] + adv;
					if (i == n - 1)
					{
						flag = 1;
					}
				}
			}
		}
	}

	if (flag == 1)
	{
		cout << "-1";
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		if (d[i] == inf)
		{
			cout << "-1\n";
		}
		else
		{
			cout << d[i] << "\n";
		}
	}
}
