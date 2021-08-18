#include <queue>
#include <iostream>
#include <vector>

using namespace std;

const int infi = 214854560;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int dist[101][101];
int nyan[101][101];
int n, m;

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &nyan[j][i]);
        }
    }

    fill(&dist[0][0], &dist[100][101], infi);

    priority_queue<pair<int, pair<int, int>>> dij;

    dij.push({ 0, {1 , 1} });
    dist[1][1] = 0;

    while (!dij.empty())
    {
        int cost = -dij.top().first;
        int hx = dij.top().second.first;
        int hy = dij.top().second.second;

        dij.pop();

        if (cost > dist[hx][hy])
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = hx + dx[i];
            int ny = hy + dy[i];
            
            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n)
            {
                int nc = nyan[nx][ny];
                if (dist[nx][ny] > cost + nc)
                {
                    dist[nx][ny] = dist[hx][hy] + nc;
                    dij.push({ -dist[nx][ny], { nx, ny } });
                }
            }
        }
    }

    cout << dist[m][n];

    return 0;
}