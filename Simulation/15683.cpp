#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct info
{
    int x;
    int y;
    int num;
};

int n, m;
int mins = 214842445;
int room[8][8] = { 0 };
int tr[8][8];
int rot[6] = { 0, 4, 2, 4, 4, 1 };

vector <info> cctv;
vector <pair<int, int>> temp;

void monitor(int cnt, int d)
{
    d %= 4;
    if (d == 0)
    {
        for (int c = cctv[cnt].x + 1; c < m; c++)
        {
            if (tr[c][cctv[cnt].y] == 6)
            {
                break;
            }
            tr[c][cctv[cnt].y] = -1;
        }
    }
    else if (d == 1)
    {
        for (int r = cctv[cnt].y - 1; r >= 0; r--)
        {
            if (tr[cctv[cnt].x][r] == 6)
            {
                break;
            }
            tr[cctv[cnt].x][r] = -1;
        }
    }
    else if (d == 2)
    {
        for (int c = cctv[cnt].x - 1; c >= 0; c--)
        {
            if (tr[c][cctv[cnt].y] == 6)
            {
                break;
            }
            tr[c][cctv[cnt].y] = -1;
        }
    }
    else if (d == 3)
    {
        for (int r = cctv[cnt].y + 1; r < n; r++)
        {
            if (tr[cctv[cnt].x][r] == 6)
            {
                break;
            }
            tr[cctv[cnt].x][r] = -1;
        }
    }
}

int check()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tr[j][i] = room[j][i];
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        int num = temp[i].first;
        int dir = temp[i].second;

        if (cctv[num].num == 1)
        {
            monitor(num, dir);
        }
        else if (cctv[num].num == 2)
        {
            monitor(num, dir);
            monitor(num, dir + 2);
        }
        else if (cctv[num].num == 3)
        {
            monitor(num, dir);
            monitor(num, dir + 1);
        }
        else if (cctv[num].num == 4)
        {
            monitor(num, dir);
            monitor(num, dir + 1);
            monitor(num, dir + 2);
        }
        else if (cctv[num].num == 5)
        {
            monitor(num, dir);
            monitor(num, dir + 1);
            monitor(num, dir + 2);
            monitor(num, dir + 3);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tr[j][i] == 0)
            {
                sum++;
            }
        }
    }
    return sum;
}

void rotate(int cnt)
{
    if (cnt == cctv.size())
    {
        mins = min(mins, check());
        return;
    }

    for (int i = 0; i < rot[cctv[cnt].num]; i++)
    {
        temp.push_back({ cnt, i });
        rotate(cnt + 1);
        temp.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[j][i];
            if (room[j][i] > 0 && room[j][i] < 6)
            {
                cctv.push_back({ j, i, room[j][i] });
            }
        }
    }

    rotate(0);

    cout << mins;

    return 0;
}