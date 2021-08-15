#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long a, b;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	queue <pair <long, long>> simsimi;
	simsimi.push({ a, 0 });

	while (!simsimi.empty())
	{
		long now = simsimi.front().first;
		long time = simsimi.front().second;

		simsimi.pop();

		if (now == b)
		{
			cout << time + 1;
			return 0;
		}

		long next = now * 2;

		if (next <= b)
		{
			simsimi.push({ next, time + 1 });
		}

		next = now * 10 + 1;

		if (next <= b)
		{
			simsimi.push({ next, time + 1 });
		}
	}

	cout << -1;

	return 0;
}