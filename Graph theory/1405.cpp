#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
double prob[4] = { 0 };
int visit[29][29] = { 0 };
double probability = 0;
void dfs(int x, int y, double p, int cnt)
{
    if (cnt == n)
    {
        probability += p;
        return;
    }

    visit[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 29 && ny >= 0 && ny < 29 && !visit[nx][ny])
        {
            dfs(nx, ny, p * prob[i], cnt + 1);
        }
    }
    visit[x][y] = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cin >> n;

    for (int i = 0; i < 4; i++)
    {
        double num;
        cin >> num;
        prob[i] = num / 100;
    }

    dfs(14, 14, 1, 0);

    cout << fixed << probability;
    return 0;
}