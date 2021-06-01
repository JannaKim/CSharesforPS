#include <deque>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int x, y, beforehour, times;
int ans, ans2;
int cheese[100][100] = {0,};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
    cin >> y >> x;

    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            cin >> cheese[j][i];
        }
    }

    int chse = 0;
    while(1)
    {
        int status[100][100] = {0,};
        for(int i = 0; i < y; i++)
        {
            memset(status, 0, sizeof(status[i]));
        }
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                if(cheese[j][i] == 1 && status[j][i] == 0)
                {
                    chse++;
                    queue <pair<int, int>> q; 
                    status[j][i] = 1;
                    q.push(make_pair(j,i));
                    while(!q.empty())
                    {
                        pair<int, int> here = q.front();
                        q.pop();
                        
                        for(int k = 0; k < 4; k++)
                        {
                            int xx = here.first + dx[k];
                            int yy = here.second + dy[k];
                            if(xx >= 0 && xx < x && yy >= 0 && yy < y && status[xx][yy] != 1)
                            {
                                if(cheese[xx][yy] == 0)
                                {
                                    status[here.first][here.second] = 2;
                                }
                                else
                                {
                                    q.push(make_pair(xx,yy));
                                    status[xx][yy] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < y; i++)
        {
            for(int j = 0; j < x; j++)
            {
                if(status[j][i] == 2)
                {
                    cheese[j][i] = 0;
                }
            }
        }
        times++;
        if(chse == 0)
        {
            ans = times;
            ans2 = beforehour;
            break;
        }
        else
        {
            beforehour = chse;
            chse = 0;
        }
    
    }
    cout << ans << "\n" << ans2;
    return 0;
}