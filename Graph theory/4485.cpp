#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

const int inf = 100000000;
int link[125][125] = { 0 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n = 1;
using namespace std;
int d[125][125];

void rupee_chatki()
{
	priority_queue <pair<int, pair<int, int>>> pq;
	int visit[125][125] = { 0 };
	fill(&d[0][0], &d[124][125], inf);
	pq.push({ link[0][0], make_pair(0, 0) });

	d[0][0] = link[0][0];
	while (!pq.empty())
	{
		int x = pq.top().second.first;
		int y = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n && visit[xx][yy] == 0)
			{
				if (d[x][y] + link[xx][yy] < d[xx][yy])
				{
					d[xx][yy] = d[x][y] + link[xx][yy];
					pq.push({ -d[xx][yy], make_pair(xx,yy) });
				}
			}
		}
	}
}
int main()
{
	int cnt = 1;
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> link[j][i];
			}
		}
		rupee_chatki();
		cout << "Problem " << cnt << ": " << d[n - 1][n - 1] << "\n";
		cnt++;
	}
}
