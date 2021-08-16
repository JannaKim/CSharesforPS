#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		queue <pair<int, int>> printer;
		int fifo[10] = { 0 };

		int n, m;
		int cnt = 1;

		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			int priority;

			cin >> priority;

			fifo[priority]++;

			printer.push({ i, priority });
		}

		while (!printer.empty())
		{
			int flag = 0;
			int num = printer.front().first;
			int pri = printer.front().second;

			printer.pop();
			for (int i = 9; i >= pri; i--)
			{
				if (fifo[i] >= 1 && i > pri)
				{
					printer.push({ num, pri });
					break;
				}
				if (i == pri)
				{
					fifo[pri]--;
					if (num == m)
					{
						cout << cnt << endl;
						break;
					}
					cnt++;
				}
			}
		}
	}

	return 0;
}