#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

int sero, garo;
using namespace std;

pair<int, int> d[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
char map[50][50];
int visit[50][50] = { 0 };
int maxx = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> sero >> garo;

	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			cin >> map[j][i];
		}
	}

	for (int i = 0; i < sero; i++)
	{
		for (int j = 0; j < garo; j++)
		{
			if (map[j][i] == 'L')
			{
				fill(&visit[0][0], &visit[49][50], 0);
				queue <pair<int, int>> traveler;
				visit[j][i] = 1;
				traveler.push(make_pair(j, i));
				while (!traveler.empty())
				{
					pair<int, int> coor = traveler.front();
					traveler.pop();
					for (int k = 0; k < 4; k++)
					{
						int x = coor.first + d[k].first;
						int y = coor.second + d[k].second;
						if (x >= 0 && x < garo && y >= 0 && y < sero && !visit[x][y] && map[x][y] == 'L')
						{
							visit[x][y] = visit[coor.first][coor.second] + 1;
							traveler.push(make_pair(x, y));
							if (maxx < visit[x][y])
							{
								maxx = visit[x][y];
							}
						}
					}
				}
			}
		}
	}
	cout << maxx - 1;
}