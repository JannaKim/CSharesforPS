#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int map[101][101] = { 0 };

int n;
int cnt = 0;

struct info
{
	int x;
	int y;
	int d;
	int g;
};

vector <info> gd;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		map[a][b] = 1;

		gd.push_back({ a, b, c, d });
	}

	for (int i = 0; i < n; i++)
	{
		vector <int> drc;

		drc.push_back(gd[i].d);

		int lx = gd[i].x;
		int ly = gd[i].y;

		for (int j = 1; j <= gd[i].g; j++)
		{
			int size = drc.size() - 1;

			for (int k = size; k >= 0; k--)
			{
				int dir = drc[k];
				drc.push_back((drc[k] + 1) % 4);
			}
		}
		
		for (int j = 0; j < drc.size(); j++)
		{
			lx += dx[drc[j]];
			ly += dy[drc[j]];

			map[lx][ly] = 1;
		}
	}

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (map[j][i] == 1 && map[j][i + 1] == 1 && map[j + 1][i] == 1 && map[j + 1][i + 1] == 1)
			{
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}