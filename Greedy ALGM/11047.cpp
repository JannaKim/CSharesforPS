#include <iostream>
#include <vector>

using namespace std;

int n, k;
int used[10] = { 0 };
int mul[10] = { 0 };
vector <int> coin;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		coin.push_back(a);
	}
	for (int i = 1; i < n; i++)
	{
		mul[i - 1] = coin[i] / coin[i - 1];
	}
	int sum = k;
	for (int i = coin.size() - 1; i >= 0; i--)
	{
		if (coin[i] <= sum)
		{
			while (sum >= 0)
			{
				sum -= coin[i];
				if (sum < 0)
				{
					sum += coin[i];
					break;
				}
				used[i]++;
			}
		}
	}
	sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (used[i] >= mul[i])
		{
			used[i] -= mul[i];
			used[i + 1]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum += used[i];
	}
	cout << sum;
	return 0;
}