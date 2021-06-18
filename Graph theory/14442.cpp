#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int n, m, k;
int world[1000][1000];
int visit[1000][1000][11] = { 0 };

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

struct man
{
    int x;
    int y;
    int through;
};

void BFS()
{
    queue <man> gada;
    man go;

    gada.push({0, 0, 0});
    visit[0][0][0] = 1;
    while (!gada.empty())
    {
        int hx = gada.front().x;
        int hy = gada.front().y;
        int hcnt = gada.front().through;

        gada.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = hx + dx[i];
            int ny = hy + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny][hcnt])
            {
                if (world[nx][ny] == 0)
                {
                    visit[nx][ny][hcnt] = visit[hx][hy][hcnt] + 1;
                    gada.push({ nx, ny, hcnt });
                }
                else if (world[nx][ny] == 1 && hcnt < k)
                {
                    visit[nx][ny][hcnt + 1] = visit[hx][hy][hcnt] + 1;
                    gada.push({ nx, ny, hcnt + 1 });
                }
            }
        }
    }
}

int main()
{
    int min = 999999999;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &world[j][i]);
        }
    }
    BFS();

    for (int i = 0; i <= k; i++)
    {
        if (visit[m - 1][n - 1][i] && min > visit[m - 1][n - 1][i])
        {
            min = visit[m - 1][n - 1][i];
        }
    }
    if(min == 999999999)
    {
        cout << -1;
    }
    else
    {
        cout << min;
    }
    return 0;
}