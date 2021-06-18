#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int t, length;
int visit[11][1000001] = { 0 };
string input;

int swap(string &n, int i, int j)
{
    char temp;
    if (i == 0 && n[j] == '0')
    {
        return 0;
    }
    temp = n[i];
    n[i] = n[j];
    n[j] = temp;
    return 1;
}

string BFS()
{
    int flag = 0;
    string ans = "0";
    queue <pair<string, int>> exch;

    exch.push({ input, 0 });
    
    while (!exch.empty())
    {
        string now = exch.front().first;
        int cnt = exch.front().second;

        exch.pop();

        if (cnt == t)
        {
            if (ans < now)
            {
                ans = now;
            }
        }
        if (cnt == t + 1)
        {
            return ans;
        }
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                string next = now;
                int ex = 0;
                ex = swap(next, i, j);
                if (ex == 1)
                {
                    visit[cnt][stoi(next)] = 1;
                    exch.push(make_pair(next, cnt + 1));
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            return "-1";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> input;

    length = input.length();

    cin >> t;
 
    cout << BFS() << '\n';

    return 0;
}