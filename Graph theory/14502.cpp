#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
int lab[8][8];
int temp[8][8];
int maxx = 0;

queue <pair<int, int>> q;

void virus_spread()
{
	queue <pair<int, int>> virus;

	virus = q;

	int labo[8][8];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			labo[j][i] = temp[j][i];
		}
	}

	int safety_zone = 0;

	while (!virus.empty())
	{
		int x = virus.front().first;
		int y = virus.front().second;

		virus.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < m && ny >= 0 && ny < n && labo[nx][ny] == 0)
			{
				labo[nx][ny] = 2;
				virus.push({ nx, ny });
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (labo[j][i] == 0)
			{
				safety_zone++;
			}
		}
	}
	if (safety_zone > maxx)
	{
		maxx = safety_zone;
	}

	return;
}

void build_wall(int cnt)
{
	if (cnt == 3)
	{
		virus_spread();
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[j][i] == 0)
			{
				temp[j][i] = 1;
				build_wall(cnt + 1);
				temp[j][i] = 0;
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> lab[j][i];
			if (lab[j][i] == 2)
			{
				q.push({ j, i });
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[j][i] = lab[j][i];
		}
	}
	build_wall(0);

	cout << maxx;
	return 0;
}