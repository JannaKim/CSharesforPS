#include <iostream>

using namespace std;

int n;
int cost[1000][3];
int minimum[1000][3];

const int maxi = 100000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(&minimum[0][0], &minimum[n - 1][3], maxi);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }
    for (int j = 0; j < 3; j++)
    {
        minimum[0][j] = cost[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j != k)
                {
                    if (minimum[i][k] > minimum[i - 1][j] + cost[i][k])
                    {
                        minimum[i][k] = minimum[i - 1][j] + cost[i][k];
                    }
                }
            }
        }
    }

    cout << min(minimum[n - 1][0], min(minimum[n - 1][1], minimum[n - 1][2]));

    return 0;
}
