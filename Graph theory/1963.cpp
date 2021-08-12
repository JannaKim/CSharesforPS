#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t;
int primecheck[10000];
int visit[10000];

void check()
{
	fill(&primecheck[0], &primecheck[10000], 1);

	for (int i = 2; i*i < 10000; i++)
	{
		if (primecheck[i])
		{
			for (int j = i * i; j < 10000; j += i)
			{
				primecheck[j] = 0;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	check();

	cin >> t;

	while (t--)
	{
		fill(&visit[0], &visit[10000], 0);
		
		int flag = 0;
		int a, b;

		cin >> a >> b;

		if (a == b)
		{
			cout << 0 << endl;
			continue;
		}
		queue <int> bfs;

		bfs.push(a);

		visit[a] = 1;

		while (!bfs.empty())
		{
			int now = bfs.front();
			bfs.pop();

			for (int i = 0; i < 4; i++)
			{
				int digit[4];

				digit[0] = now / 1000;
				digit[1] = (now % 1000) / 100;
				digit[2] = (now % 100) / 10;
				digit[3] = now % 10;

					for (int j = 0; j < 10; j++)
					{
						digit[i] = j;

						int next = digit[0] * 1000 + digit[1] * 100 + digit[2] * 10 + digit[3];

						if (next >= 1000 && next < 10000 && !visit[next])
						{
							if (next == b)
							{
								visit[next] = visit[now] + 1;
								flag = 1;
								break;
							}

							if (primecheck[next])
							{
								visit[next] = visit[now] + 1;
								bfs.push(next);
							}
						}
					}
				if (flag)
				{
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
		if (visit[b])
		{
			cout << visit[b] - 1 << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
