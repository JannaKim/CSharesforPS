#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int n;
char common[100][100] = { 0 };
char blind[100][100] = { 0 };
int visit[100][100] = { 0 };
int ans[2] = { 0 };
void bfs(char paper[100][100], int x, int y)
{
    char color = paper[x][y];

    visit[x][y] = 1;

    queue <pair<int, int>> qs;
    qs.push(make_pair(x, y));
    while (!qs.empty())
    {
        pair<int, int> here = qs.front();
        qs.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = here.first + dx[k];
            int ny = here.second + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny] && paper[nx][ny] == color)
            {
                visit[nx][ny] = 1;
                qs.push(make_pair(nx, ny));
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            common[j][i] = ch;
            if (ch == 'R' || ch == 'G')
            {
                blind[j][i] = 'R';
            }
            else
            {
                blind[j][i] = ch;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[j][i])
            {
                bfs(common, j, i);
                ans[0]++;
            }
        }
    }

    fill(&visit[0][0], &visit[99][100], 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visit[j][i])
            {
                bfs(blind, j, i);
                ans[1]++;
            }
        }
    }

    cout << ans[0] << " " << ans[1];
    return 0;
}