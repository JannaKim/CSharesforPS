#include <iostream>

using namespace std;

int n;
int card[1001];
int price[1001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> card[i];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i + j <= n)
			{
				price[i + j] = max(price[i + j], price[i] + card[j]);
			}
		}
	}

	cout << price[n];

	return 0;
}