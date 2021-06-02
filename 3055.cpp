#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int x, y, cn, cnn;
pair<int, int> start;
pair<int, int> dest;
queue <pair<int, int>> water;

int ans, ans2;
int maze[100][100] = { 0, };
int status[100][100] = { 0, };
int visited[100][100] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
    cin >> y >> x;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'S')
            {
                maze[j][i] = 0;
                visited[j][i] = 1;
                start.first = j;
                start.second = i;
                cnn++;
            }
            else if (ch == '*')
            {
                maze[j][i] = 1;
                status[j][i] = -1;
                water.push(make_pair(j, i));
                cn++;
            }
            else if (ch == 'D')
            {
                maze[j][i] = 0;
                status[j][i] = 4;
                dest.first = j;
                dest.second = i;
            }
            else if (ch == 'X')
            {
                maze[j][i] = 5;
                status[j][i] = 1;
            }
            else
            {
                maze[j][i] = 0;
            }
        }
    }
    queue <pair<int, int>> dochi;

    dochi.push(start);
    int cnt = 1;
    while (!dochi.empty())
    {
        if (!water.empty())
        {
            int cn1 = cn;
            cn = 0;
            for (int a = 0; a < cn1; a++)
            {
                pair<int, int> here = water.front();
                water.pop();

                for (int k = 0; k < 4; k++)
                {
                    int xx = here.first + dx[k];
                    int yy = here.second + dy[k];
                    if (xx >= 0 && xx < x && yy >= 0 && yy < y && maze[xx][yy] == 0 && status[xx][yy] != 4)
                    {
                        cn++;
                        maze[xx][yy] = 1;
                        status[xx][yy] = -1;
                        water.push(make_pair(xx, yy));
                    }
                }
            }

        }
        int cn2 = cnn;
        cnn = 0;
        for (int a = 0; a < cn2; a++)
        {
            pair<int, int> mole = dochi.front();
            dochi.pop();

            for (int k = 0; k < 4; k++)
            {
                int xx = mole.first + dx[k];
                int yy = mole.second + dy[k];
                if (xx >= 0 && xx < x && yy >= 0 && yy < y && maze[xx][yy] == 0 && visited[xx][yy] == 0)
                {
                    cnn++;
                    dochi.push(make_pair(xx, yy));
                    visited[xx][yy] = visited[mole.first][mole.second] + 1;
                }
            }
        }
    }
    if (visited[dest.first][dest.second] == 0)
    {
        cout << "KAKTUS";
        return 0;
    }

    cout << visited[dest.first][dest.second] - 1;
    return 0;
}