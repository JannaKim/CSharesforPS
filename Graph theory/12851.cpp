#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int visit[200001] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	int least = -999;
	cin >> n >> k;

	queue <pair<int, int>> kakurenbo;

	kakurenbo.push( { n, 0 } );

	while (!kakurenbo.empty())
	{
		int here = kakurenbo.front().first;
		int time = kakurenbo.front().second;

		kakurenbo.pop();

		visit[here] = 1;

		if (here == k && cnt == 0)
		{
			least = time;
			cnt++;
			continue;
		}
		else if (here == k && time == least)
		{
			cnt++;
		}
		

		int next = 2 * here;

		if (100000 >= next)
		{
			if (!visit[next])
			{
				kakurenbo.push({ next, time + 1 });
			}
		}

		for (int i = -1; i <= 1; i += 2)
		{
			next = here + i;

			if (next >= 0 && next <= 200000)
			{
				if (!visit[next])
				{
					kakurenbo.push({ next, time + 1 });
				}
			}
		}
	}

	cout << least << endl << cnt;

	return 0;
}