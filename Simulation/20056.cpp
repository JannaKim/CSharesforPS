#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct meteor
{
	int x;
	int y;
	int mass;
	int spd;
	int dir;
};

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int n, m, k;

vector <meteor> me;

vector <int> map[50][50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int r, c, m, s, d;
		cin >> c >> r >> m >> s >> d;
		me.push_back({ r - 1,c - 1,m,s,d });
	}
	while (k--)
	{
		vector <meteor> temp_me;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[j][i].clear();
			}
		}

		int size = me.size();
		for (int i = 0; i < size; i++)
		{
			me[i].x = (me[i].x + me[i].spd * dx[me[i].dir] + n * 1000) % n;
			me[i].y = (me[i].y + me[i].spd * dy[me[i].dir] + n * 1000) % n;
			map[me[i].x][me[i].y].push_back(i);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int sum_meteor = map[j][i].size();
				if (sum_meteor >= 2)
				{
					int flag = 0;
					int disc = me[map[j][i][0]].dir;
					int sum_mass = me[map[j][i][0]].mass;
					int sum_spd = me[map[j][i][0]].spd;
					
					for (int a = 1; a < map[j][i].size(); a++)
					{
						sum_mass += me[map[j][i][a]].mass;
						sum_spd += me[map[j][i][a]].spd;

						if (disc % 2 != me[map[j][i][a]].dir % 2)
						{
							flag = 1;
						}
					}
					if ((sum_mass / 5) != 0)
					{
						if (flag == 1)
						{
							for (int odd = 1; odd < 8; odd += 2)
							{
								temp_me.push_back({ j, i, sum_mass / 5, sum_spd / sum_meteor, odd });
							}
						}
						else
						{
							for (int even = 0; even < 8; even += 2)
							{
								temp_me.push_back({ j, i, sum_mass / 5, sum_spd / sum_meteor, even });
							}
						}
					}
				}
				else if (sum_meteor == 1)
				{
					int num = map[j][i].back();
					temp_me.push_back({ me[num].x, me[num].y, me[num].mass, me[num].spd, me[num].dir });
				}
			}
		}
		me = temp_me;
	}
	int summary = 0;
	for (int i = 0; i < me.size(); i++)
	{
		summary += me[i].mass;
	}
	cout << summary;
	return 0;
}