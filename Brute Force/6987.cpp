#include <iostream>
#include <vector>

using namespace std;

struct ctr
{
    int win;
    int draw;
    int lose;
};

int n;

int pairOfElement[15][2];
int visit[6][6];
int success;
int flag[4] = { 0 };

vector <ctr> country[4];

void play(int round, int cnt)
{
    if (cnt == 15)
    {
        success = 1;
        return;
    }

    int a = pairOfElement[cnt][0];
    int b = pairOfElement[cnt][1];

    if (country[round][a].win > 0 && country[round][b].lose > 0)
    {
        country[round][a].win--;
        country[round][b].lose--;
        play(round, cnt + 1);
        country[round][a].win++;
        country[round][b].lose++;
    }
    if (country[round][b].win > 0 && country[round][a].lose > 0)
    {
        country[round][b].win--;
        country[round][a].lose--;
        play(round, cnt + 1);
        country[round][b].win++;
        country[round][a].lose++;
    }
    if (country[round][a].draw > 0 && country[round][b].draw > 0)
    {
        country[round][a].draw--;
        country[round][b].draw--;
        play(round, cnt + 1);
        country[round][a].draw++;
        country[round][b].draw++;
    }

    return;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 6; j++)
        {
            int a, b, c;

            cin >> a >> b >> c;

            if (a > 5 || b > 5 || c > 5)
            {
                flag[i] = 1;
            }
            sum += a + b + c;
            country[i].push_back({ a, b, c });
        }
        if (sum != 30)
        {
            flag[i] = 1;
        }
    }

    int cnt = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j != i && !visit[j][i])
            {
                visit[i][j] = 1;
                visit[j][i] = 1;
                pairOfElement[cnt][0] = i;
                pairOfElement[cnt][1] = j;
                cnt++;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        success = 0;

        if (flag[i] == 0)
        {
            play(i, 0);
        }
        cout << success << " ";
    }
    return 0;
}
