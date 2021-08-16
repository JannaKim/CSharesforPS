#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int village[50][50];
vector <pair<int, int>> temp_ckh;
vector <pair<int, int>> house;
vector <pair<int, int>> ckh;

int mins = 214834532;

int chk_dist()
{
	int sum = 0;

	for (int i = 0; i < house.size(); i++)
	{
		int dist = 214843251;

		for (int j = 0; j < temp_ckh.size(); j++)
		{
			dist = min(dist, (abs(house[i].first - temp_ckh[j].first) + abs(house[i].second - temp_ckh[j].second)));
		}

		sum += dist;
	}
	return sum;
}

void dfs(int now, int cnt)
{
	if (now > ckh.size())
	{
		return;
	}

	if (cnt == m)
	{
		mins = min(mins, chk_dist());
		return;
	}

	temp_ckh.push_back({ ckh[now].first, ckh[now].second });
	dfs(now + 1, cnt + 1);
	temp_ckh.pop_back();
	dfs(now + 1, cnt);

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> village[j][i];

			if (village[j][i] == 1)
			{
				house.push_back({ j, i });
			}
			else if (village[j][i] == 2)
			{
				ckh.push_back({ j, i });
			}
		}
	}

	dfs(0, 0);

	cout << mins;

	return 0;
}
