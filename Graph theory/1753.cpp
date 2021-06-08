#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999

using namespace std;

int v, e, k;

vector<pair<int, int>> line[20001];

int main()
{
	scanf("%d %d %d", &v, &e, &k);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		line[a].push_back(make_pair(b, c));
	}
	vector<int>dist(v + 1, INF);

	priority_queue <pair<int, int>> di;

	di.push(make_pair(0, k));

	dist[k] = 0;

	while (!di.empty())
	{
		int adv = -di.top().first;
		int now = di.top().second;

		di.pop();

		if (dist[now] < adv)
		{
			continue;
		}

		int size = line[now].size();
		for (int i = 0; i < size; i++)
		{
			int daum = line[now][i].first;
			int daumadv = line[now][i].second;

			if (dist[daum] > dist[now] + daumadv)
			{
				dist[daum] = dist[now] + daumadv;
				di.push(make_pair(-dist[daum], daum));
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] != INF)
		{
			printf("%d\n", dist[i]);
		}
		else
		{
			printf("INF\n");
		}
	}
}
