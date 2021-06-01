#define _CRT_SECURE_NO_WARNINGS

#include <deque>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int x, y, beforehour, times;
int ans, ans2;
int cheese[100][100] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


int main()
{
    cin >> y >> x;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cin >> cheese[j][i];
        }
    }

    int chse = 0;
    while (1)
    {
        int status[100][100] = { 0, };

        queue <pair<int, int>> qs;
        status[0][0] = -1;
        qs.push(make_pair(0, 0));
        while (!qs.empty())
        {
            pair<int, int> here = qs.front();
            qs.pop();

            for (int k = 0; k < 4; k++)
            {
                int xx = here.first + dx[k];
                int yy = here.second + dy[k];
                if (xx >= 0 && xx < x && yy >= 0 && yy < y && status[xx][yy] == 0 && cheese[xx][yy] == 0)
                {
                    status[xx][yy] = -1;
                    qs.push(make_pair(xx, yy));
                }
            }
        }

        for (int i = 1; i < y - 1; i++)
        {
            for (int j = 1; j < x - 1; j++)
            {
                if (cheese[j][i] == 1 && status[j][i] == 0)
                {
                    queue <pair<int, int>> q;
                    status[j][i] = 1;
                    q.push(make_pair(j, i));
                    chse++;
                    while (!q.empty())
                    {
                        pair<int, int> here = q.front();
                        q.pop();
                        
                        for (int k = 0; k < 4; k++)
                        {
                            int xx = here.first + dx[k];
                            int yy = here.second + dy[k];
                            if (xx >= 0 && xx < x && yy >= 0 && yy < y)
                            {
                                if (cheese[xx][yy] == 0 && status[xx][yy] == -1)
                                {
                                    status[here.first][here.second] = 2;
                                }
                                else if (cheese[xx][yy] == 1 && status[xx][yy] == 0)
                                {
                                    chse++;
                                    status[xx][yy] = 1;
                                    q.push(make_pair(xx, yy));
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (status[j][i] == 2)
                {
                    cheese[j][i] = 0;
                }
            }
        }
        if (chse == 0)
        {
            ans = times;
            ans2 = beforehour;
            break;
        }
        else
        {
            beforehour = chse;
            times++;
            chse = 0;
        }
    }
    cout << ans << "\n" << ans2;
    return 0;
}