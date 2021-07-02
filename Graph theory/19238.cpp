#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

struct guest
{
    int ax;
    int ay;
    int dstx;
    int dsty;
    int carried;
};

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int n, m, fuel, tx, ty;
int field[21][21];

vector <guest> q;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> fuel;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                field[j][i] = -1;
            }
            else
            {
                field[j][i] = 0;
            }
        }
    }

    cin >> ty >> tx;

    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> b >> a >> d >> c;

        q.push_back({ a, b, c, d });
    }

    for (int i = 0; i < q.size(); i++)
    {
        int flag = 0;
        int thisguest = 0;
        queue<pair<int, int>> navi;

        int visit[21][21] = { 0 };
        int restoffuel[21][21] = { 0 };

        navi.push({ tx, ty });
        visit[tx][ty] = 1;
        restoffuel[tx][ty] = fuel;

        while (!navi.empty())
        {
            int hx = navi.front().first;
            int hy = navi.front().second;

            navi.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = hx + dx[k];
                int ny = hy + dy[k];

                if (nx > 0 && nx <= n && ny > 0 && ny <= n && !visit[nx][ny] && field[nx][ny] != -1)
                {
                    visit[nx][ny] = visit[hx][hy] + 1;
                    restoffuel[nx][ny] = restoffuel[hx][hy] - 1;
                    navi.push({ nx, ny });
                }
            }
        }
        int maxdis = 123456789;
        int index = -1;
        for (int g = 0; g < q.size(); g++)
        {
            if (q[g].carried == 0 && restoffuel[q[g].ax][q[g].ay] >= 0)
            {
                int x = q[g].ax;
                int y = q[g].ay;
                if (visit[x][y] - 1 < maxdis)
                {
                    tx = x;
                    ty = y;
                    index = g;
                    maxdis = visit[x][y] - 1;
                }
                else if (visit[x][y] - 1 == maxdis)
                {
                    if (ty > y) {
                        ty = y;
                        tx = x;
                        index = g;
                    }
                    else if (tx > x && ty == y) {
                        ty = y;
                        tx = x;
                        index = g;
                    }
                }
            }
        }
        q[index].carried = 1;
        if (index == -1)
        {
            cout << -1;
            return 0;
        }
        thisguest = index;
        queue<pair<int, int>> gotodest;

        int temp = restoffuel[tx][ty];

        gotodest.push({ tx, ty });

        int revisit[21][21] = { 0 };

        while (!gotodest.empty())
        {
            int hx = gotodest.front().first;
            int hy = gotodest.front().second;

            gotodest.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = hx + dx[k];
                int ny = hy + dy[k];

                if (nx > 0 && nx <= n && ny > 0 && ny <= n && !revisit[nx][ny] && field[nx][ny] != -1)
                {
                    revisit[nx][ny] = 1;
                    restoffuel[nx][ny] = restoffuel[hx][hy] - 1;

                    if (restoffuel[nx][ny] < 0)
                    {
                        cout << -1;
                        return 0;
                    }

                    if (nx == q[thisguest].dstx && ny == q[thisguest].dsty)
                    {
                        fuel = restoffuel[nx][ny] + (temp - restoffuel[nx][ny]) * 2;
                        flag = 1;
                        tx = nx;
                        ty = ny;
                        break;
                    }
                    gotodest.push({ nx, ny });
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 0)
        {
            cout << -1;
            return 0;
        }
    }
    cout << fuel;
    return 0;
}