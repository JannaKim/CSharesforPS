#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int inf = 123456789;
int T;
int n, m, t, s, g, h;

vector<pair<int, int>> road[2001];
vector<int> candidate;

vector<int> dijkstra(int start)
{
    vector <int> dist(n + 1, inf);
    priority_queue <pair<int, int>> dij;
    dij.push({ 0, start });

    dist[start] = 0;

    while (!dij.empty())
    {
        long long cost = -dij.top().first;
        int here = dij.top().second;

        dij.pop();

        if (cost > dist[here])
        {
            continue;
        }

        for (int i = 0; i < road[here].size(); i++)
        {
            int next = road[here][i].first;
            long long ncost = cost + road[here][i].second;

            if (dist[next] > ncost)
            {
                dist[next] = ncost;
                dij.push({ -ncost, next });
            }
        }
    }
    return dist;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int times = 0; times < T; times++)
    {
        int specific;

        candidate.clear();

        cin >> n >> m >> t;

        cin >> s >> g >> h;

        for (int i = 0; i <= n; i++)
        {
            road[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            int d;

            cin >> a >> b >> d;

            road[a].push_back(make_pair(b, d));
            road[b].push_back(make_pair(a, d));

            if ((a == g && b == h) || (a == h && b == g))
            {
                specific = d;
            }
        }

        for (int i = 0; i < t; i++)
        {
            int x;
            cin >> x;
            candidate.push_back(x);
        }

        sort(candidate.begin(), candidate.end());

        vector<int> temp1 = dijkstra(s);
        vector<int> temp2 = dijkstra(g);
        vector<int> temp3 = dijkstra(h);

        for (int i = 0; i < candidate.size(); i++)
        {
            int result1 = temp1[g] + specific + temp3[candidate[i]];
            int result2 = temp1[h] + specific + temp2[candidate[i]];
            int mins;
            if (result1 < result2)
            {
                mins = result1;
            }
            else
            {
                mins = result2;
            }

            int result3 = temp1[candidate[i]];

            if (mins <= result3)
            {
                cout << candidate[i] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}