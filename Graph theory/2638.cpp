#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int n, m, hour;
int cheese[100][100] = { 0 };
int visit[100][100] = { 0 };
int status[100][100] = { 0 };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cheese[j][i];
        }
    }

    while (1)
    {
        fill(&visit[0][0], &visit[99][100], 0);
        fill(&status[0][0], &status[99][100], 0);

        queue <pair<int, int>> air;

        air.push({ 0, 0 });
        status[0][0] = -1;

        while (!air.empty())
        {
            pair<int, int> here = air.front();

            air.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = here.first + dx[k];
                int ny = here.second + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && status[nx][ny] == 0 && !cheese[nx][ny])
                {
                    status[nx][ny] = -1;
                    air.push({ nx, ny });
                }
            }
        }

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (cheese[j][i] && !visit[j][i])
                {
                    queue <pair<int, int>> ch;

                    visit[j][i] = 1;

                    ch.push({ j, i });

                    while (!ch.empty())
                    {
                        int hx = ch.front().first;
                        int hy = ch.front().second;

                        ch.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int nx = hx + dx[k];
                            int ny = hy + dy[k];

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                            {
                                if (!cheese[nx][ny] && status[nx][ny] == -1)
                                {
                                    status[hx][hy]++;
                                }
                                else if (cheese[nx][ny] && !visit[nx][ny])
                                {
                                    visit[nx][ny] = 1;
                                    ch.push({ nx, ny });
                                }
                            }
                        }
                    }
                }
            }
        }
        int cheese_num = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (status[j][i] >= 2)
                {
                    cheese[j][i] = 0;
                }
                if (cheese[j][i])
                {
                    cheese_num++;
                }
            }
        }

        hour++;

        if (!cheese_num)
        {
            break;
        }
    }
    cout << hour;
    return 0;
}