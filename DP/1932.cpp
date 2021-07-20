#include <iostream>

using namespace std;

int n;

int triangle[500][500];
int dp[500][500];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][n - 1] = triangle[i][n - 1];
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            dp[j][i - 1] = triangle[j][i - 1] + max(dp[j][i], dp[j + 1][i]);
        }
    }

    cout << dp[0][0];
    return 0;
}