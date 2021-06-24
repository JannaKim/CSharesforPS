#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
const int inf = 123456789;
int n;
int room[51][51];
int dist[51][51];
priority_queue <pair<int, pair<int, int>>> dij;

int main(void)
{
    fill(&dist[0][0], &dist[50][51], inf);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            scanf("%1d", &num);
            if (num == 1)
            {
                room[j][i] = 0;
            }
            else
            {
                room[j][i] = 1;
            }
        }
    }
    dij.push({ 0, { 1 ,1 } });
    dist[1][1] = 0;

    while (!dij.empty())
    {
        int cost = -dij.top().first;
        int hx = dij.top().second.first;
        int hy = dij.top().second.second;

        dij.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = hx + dx[i];
            int ny = hy + dy[i];
            int ncost = cost + room[nx][ny];

            if (nx > 0 && nx <= n && ny > 0 && ny <= n)
            {
                if (dist[nx][ny] > ncost)
                {
                    dist[nx][ny] = ncost;
                    dij.push({ -ncost, { nx, ny } });
                }
            }
        }
    }

    cout << dist[n][n];
    return 0;
}