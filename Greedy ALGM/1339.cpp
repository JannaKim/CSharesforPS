#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int n;
int quantity[26] = { 0 };
string num[10];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int a = 0; a < n; a++)
    {
        cin >> num[a];
        int size = num[a].length();
        for (int i = 0; i < size; i++)
        {
            quantity[num[a][i] - 'A'] += pow(10, size - i - 1);
        }
    }

    sort(quantity, quantity + 26);

    int cnt = 9;
    int result = 0;

    for (int a = 0; a < 26; a++)
    {
        result += quantity[25 - a] * cnt;
        cnt--;
        if (quantity[25 - a] == 0)
        {
            break;
        }
    }
        
    cout << result;
    return 0;
}
