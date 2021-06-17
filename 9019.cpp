#include <math.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, input, output;
int visit[10001] = { 0 };

int cmd(int i, int input)
{
    int temps = 0;
    if (i == 0)
    {
        temps = (input * 2) % 10000;
    }
    else if (i == 1)
    {
        temps = input - 1;
        if (temps < 0)
        {
            temps = 9999;
        }
    }
    else if (i == 2)
    {
        temps = (input % 1000) * 10 + input / 1000;
    }
    else
    { 
        temps = (input / 10) + (input % 10) * 1000;
    }
    return temps;
}

string BFS()
{
    queue <pair<int, string>> reg;

    reg.push(make_pair(input, ""));
    visit[input] = 1;

    while (!reg.empty())
    {
        int temp = 0;
        int now = reg.front().first;
        string com = reg.front().second;
        reg.pop();
        if (now == output)
        {
            return com;
        }
        for (int i = 0; i < 4; i++)
        {
            temp = cmd(i, now);
            if (!visit[temp])
            {
                string ch;
                if (i == 0)
                {
                    ch = "D";
                }
                if (i == 1)
                {
                    ch = "S";
                }
                if (i == 2)
                {
                    ch = "L";
                }
                if (i == 3)
                {
                    ch = "R";
                }
                visit[temp] = 1;
                reg.push(make_pair(temp, com + ch));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
 
    while (t--)
    {
        fill(&visit[0], &visit[10001], 0);

        cin >> input >> output;
        cout << BFS() << '\n';
    }
    return 0;
}