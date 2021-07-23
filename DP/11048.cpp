#include <iostream>

using namespace std;

int maze[1001][1001];
int dp[1001][1001] = { 0 };
int n, m;

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> maze[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1],max(dp[i][j - 1], dp[i - 1][j]))) + maze[i][j];
		}
	}
    cout << dp[n][m];
    return 0;
}