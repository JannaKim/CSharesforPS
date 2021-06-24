#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long inf = 123456789000;
long long minx = inf;
int n, m, k;
long long dist[21][10001];
priority_queue <pair<long long, pair<int, int>>> dij;
vector<pair<int, int>> road[10001];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(&dist[0][0], &dist[20][10001], inf);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int s, e, t;

        cin >> s >> e >> t;
        road[s].push_back(make_pair(e, t));
        road[e].push_back(make_pair(s, t));
    }

    dij.push({ 0, { 1, 0 } });;
    dist[0][1] = 0;

    while (!dij.empty())
    {
        long long cost = -dij.top().first;
        int here = dij.top().second.first;
        int cnt = dij.top().second.second;

        dij.pop();

        if (cost > dist[cnt][here])
        {
            continue;
        }

        for (int i = 0; i < road[here].size(); i++)
        {
            int next = road[here][i].first;
            long long ncost = cost + road[here][i].second;

            if (dist[cnt][next] > ncost)
            {
                dist[cnt][next] = ncost;
                dij.push({ -ncost, { next, cnt } });
            }
            
            if (k > cnt && dist[cnt + 1][next] > cost)
            {
                dist[cnt + 1][next] = cost;
                dij.push({ -cost, { next, cnt + 1 } });
            }
        }
    }
    for (int i = 0; i <= k; i++)
    {
        if (minx > dist[i][n])
        {
            minx = dist[i][n];
        }
    }
    cout << minx;
    return 0;
}