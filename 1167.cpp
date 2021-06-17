#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int maxnum, maxlen = 0;

vector <pair<int, long>> tree[100001];
int visit[100001] = { 0 };

void dfs(int a, long l)
{
    if (visit[a])
    {
        return;
    }
    visit[a] = 1;
    if (maxlen < l)
    {
        maxnum = a;
        maxlen = l;
    }

    for (int i = 0; i < tree[a].size(); i++)
    {
        int next = tree[a][i].first;
        long length = tree[a][i].second;
        dfs(next, l + length);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b ,c;
        cin >> a;
        while (1)
        {
            cin >> b;
            if (b == -1)
            {
                break;
            }
            cin >> c;
            tree[a].push_back({ b, c });
            tree[b].push_back({ a, c });
        }
    }

    dfs(1, 0);

    fill(&visit[0], &visit[100001], 0);
    maxlen = 0;
    dfs(maxnum, 0);

    cout << maxlen;
    return 0;
}