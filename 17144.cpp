#include <deque>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int r, c, t;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 }; // 위 오른 아래 왼

int happyhome[50][50] = { 0 };

queue<pair<int, int>> fresh;

void circulate(int clockwise, int sty)
{
    int stx = 0;
    if (clockwise == 0)
    {
        for (int i = sty - 1; i > 0; i--)
        {
            happyhome[stx][i] = happyhome[stx][i - 1];
        }
        for (int i = stx; i < c - 1; i++)
        {
            happyhome[i][0] = happyhome[i + 1][0];
        }
        for (int i = 0; i < sty; i++)
        {
            happyhome[c - 1][i] = happyhome[c - 1][i + 1];
        }
        for (int i = c - 1; i > stx + 1; i--)
        {
            happyhome[i][sty] = happyhome[i - 1][sty];
        }
        happyhome[stx + 1][sty] = 0;
    }
    else
    {
        for (int i = sty + 2; i < r; i++)
        {
            happyhome[stx][i - 1] = happyhome[stx][i];
        }
        for (int i = stx; i < c - 1; i++)
        {
            happyhome[i][r - 1] = happyhome[i + 1][r - 1];
        }
        for (int i = r - 1; i > sty; i--)
        {
            happyhome[c - 1][i] = happyhome[c - 1][i - 1];
        }
        for (int i = c - 1; i > stx + 1; i--)
        {
            happyhome[i][sty] = happyhome[i - 1][sty];
        }
        happyhome[stx + 1][sty] = 0;
    }
}

int main()
{
    int fresher[2] = { 0 };
    int num = 0, sum = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> happyhome[j][i];
            if (happyhome[j][i] > 0)
            {
                fresh.push(make_pair(j, i));
            }
            else if (happyhome[j][i] == -1 && happyhome[j][i - 1] == -1)
            {
                fresher[0] = i - 1;
                fresher[1] = i;
            }
        }
    }
    for (int time = 0; time < t; time++)
    {
        int pmworld[50][50] = { 0 };
        for (int y = 0; y < r; y++)
        {
            for (int x = 0; x < c; x++)
            {
                int cnt = 0;
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= c || ny < 0 || ny >= r)
                    {
                        continue;
                    }
                    if ((ny == fresher[0] || ny == fresher[1]) && nx == 0)
                    {
                        continue;
                    }
                    pmworld[nx][ny] += happyhome[x][y] / 5;
                    cnt++;
                }
                happyhome[x][y] -= (happyhome[x][y] / 5) * cnt;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                happyhome[j][i] += pmworld[j][i];
            }
        }
        circulate(0, fresher[0]);
        circulate(1, fresher[1]);
    }
        
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (happyhome[j][i] > 0)
            {
                sum += happyhome[j][i];
            }
        }
    }
    cout << sum;
}