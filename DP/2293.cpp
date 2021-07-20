#include <iostream>
#include <vector>

using namespace std;

int n, k;
int coin[100];
long long dp[10001] = { 0 };

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (k >= coin[i] + j)
            {
                dp[coin[i] + j] += dp[j];
            }

        }
    }
    cout << dp[k];
    return 0;
}