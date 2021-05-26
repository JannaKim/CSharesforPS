#include <deque>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int ground[11][11];
int nutri[11][11];

deque <int> namu[11][11];
vector <int> gomok[11][11];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void s_grow()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num = namu[j][i].size();
			for (int k = 0; k < num; k++)
			{
				int nai = namu[j][i].front();
				namu[j][i].pop_front();
				if (ground[j][i] < nai)
				{
					gomok[j][i].push_back(nai);
					continue;
				}
				ground[j][i] -= nai;
				namu[j][i].push_back(nai + 1);
			}
		}
	}
}

void sum_grow()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num = gomok[j][i].size();
			for (int k = 0; k < num; k++)
			{
				int nai = gomok[j][i].back();
				gomok[j][i].pop_back();
				ground[j][i] += nai / 2;
			}
		}
	}
}

void f_grow()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num = namu[j][i].size();
			
			for (int k = 0; k < num; k++)
			{
				int nai = namu[j][i][k];
				if (nai % 5 == 0)
				{
					for (int l = 0; l < 8; l++)
					{
						int nx = j + dx[l];
						int ny = i + dy[l];
						if (nx > 0 && nx <= n && ny > 0 && ny <= n)
						{
							namu[nx][ny].push_front(1);
						}
					}
				}
			}
		}
	}
}

void w_grow()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ground[j][i] += nutri[j][i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ground[j][i] = 5;
			cin >> nutri[j][i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x;
		int y;
		int tosi;
		cin >> x >> y >> tosi;
		namu[y][x].push_back(tosi);
	}
	for (int i = 0; i < k; i++)
	{
		s_grow();
		sum_grow();
		f_grow();
		w_grow();
	}

	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum += namu[j][i].size();
		}
	}
	cout << sum;
}