#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

struct base
{
    int x;
    int y;
    int r;
};

int t;
int visit[3001] = { 0 };

vector <int> lane[3001];
vector <base> v;

bool check_dst(struct base a, struct base b)
{
    double distance;
    double radars;

    distance = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
    radars = (double)(a.r + b.r);

    if (radars >= distance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int here)
{
    visit[here] = 1;
    for (int i = 0; i < lane[here].size(); i++)
    {
        if (!visit[lane[here][i]])
        {
            dfs(lane[here][i]);
        }
    }
    return;
}

int main(void)
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int a = 0; a < t; a++)
    {
        
        int cnt = 0;
        int n;

        cin >> n;

        fill(&visit[0], &visit[n + 1], 0);

        v.clear();

        for (int i = 0; i < 3001; i++)
        {
            lane[i].clear();
        }

        for (int i = 0; i < n; i++)
        {
            int x, y, r;
            cin >> x >> y >> r;
            v.push_back({ x,y,r });
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (check_dst(v[i], v[j]) && i != j)
                {
                    lane[i].push_back(j);
                    lane[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                cnt++;
                dfs(i);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}