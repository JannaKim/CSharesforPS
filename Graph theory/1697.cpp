#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int visit[100001] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue <int> kakurenbo;

	visit[n] = 1;

	kakurenbo.push(n);

	while (!kakurenbo.empty())
	{
		int here = kakurenbo.front();

		if (here == k)
		{
			break;
		}

		kakurenbo.pop();

		if (100000 >= 2 * here && !visit[2 * here])
		{
			visit[2 * here] = visit[here] + 1;
			kakurenbo.push(2 * here);
		}
		for (int i = -1; i <= 1; i += 2)
		{
			int next = here + i;
			if (next >= 0 && next <= 100000 && !visit[next])
			{
				visit[next] = visit[here] + 1;
				kakurenbo.push(next);
			}
		}
	}

	cout << (visit[k] - 1);

	return 0;
}