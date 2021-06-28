#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int inf = 123456789;
int n, k;

int dist[100001];
int visit[100001] = { 0 };
int d[2] = { -1, 1 };

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    fill(&dist[0], &dist[100001], inf);

    priority_queue <pair<int, int>> dij;
    dij.push({ 0, n });

    dist[n] = 0;

    while (!dij.empty())
    {
        int cost = -dij.top().first;
        int here = dij.top().second;

        dij.pop();

        if (cost > dist[here])
        {
            continue;
        }

        for (int i = 0; i < 2; i++)
        {
            int next = here + d[i];
            int ncost = cost + 1;
            if (next >= 0 && next <= 100000)
            {
                if (dist[next] > ncost)
                {
                    dist[next] = ncost;
                    dij.push({ -ncost, next });
                }
            }
        }
        int next = 2 * here;
        int ncost = cost;
        if (next <= 100000)
        {
            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                dij.push({ -ncost, next });
            }
        }
    }
    cout << dist[k];
    return 0;
}