#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, erase, st;
int cnt = 0;
vector <int> tree[51];
vector <int> start;
void dfs(int a)
{
    if (tree[a].empty())
    {
        cnt++;
        return;
    }
    for (int i = 0; i < tree[a].size(); i++)
    {
        int next = tree[a][i];
        
        if (next == erase)
        {
            if (tree[a].size() == 1)
            {
                cnt++;
            }
            continue;
        }
        dfs(next);
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
        int num;
        cin >> num;
        if (num == -1)
        {
            start.push_back(i);
            continue;
        }
        tree[num].push_back(i);
    }
    cin >> erase;

    while (!start.empty())
    {
        st = start.back();
        start.pop_back();
        if (st == erase)
        {
            continue;
        }
        dfs(st);
    }
    cout << cnt;
    return 0;
}