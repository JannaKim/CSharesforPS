#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int visit[200001] = { 0 };
int path[200001];
int idx[100001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int least = -1;
	cin >> n >> k;

	queue <int> kakurenbo;

	kakurenbo.push(n);

	visit[n] = 1;

	fill(&path[0], &path[200001], -1);

	while (!kakurenbo.empty())
	{
		int here = kakurenbo.front();

		kakurenbo.pop();

		if (here == k)
		{
			least = visit[k] - 1;
			break;
		}

		if (100000 >= here)
		{
			if (!visit[2 * here])
			{
				path[2 * here] = here;
				visit[2 * here] = visit[here] + 1;
				kakurenbo.push(2 * here);
			}
		}

		for (int i = -1; i <= 1; i += 2)
		{
			int next = here + i;

			if (next >= 0 && next <= 200000)
			{
				if (!visit[next])
				{
					path[next] = here;
					visit[next] = visit[here] + 1;
					kakurenbo.push(next);
				}
			}
		}
	}

	cout << least << endl;

	int result;
	int back = k;

	idx[least] = k;

	for (int i = least - 1; i >= 0; i--)
	{
		result = back;
		idx[i] = path[result];
		back = path[result];
	}
	for (int i = 0; i <= least; i++)
	{
		cout << idx[i] << " ";
	}
	return 0;
}