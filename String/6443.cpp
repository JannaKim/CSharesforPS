#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int n, len;
int alpha[26];

void mix(string now, int cnt)
{
    if (cnt == len)
    {
        cout << now << "\n";
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i])
        {
            alpha[i]--;
            mix(now + (char)('a' + i), cnt + 1);
            alpha[i]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while(n--)
    {
        fill(&alpha[0], &alpha[26], 0);

        string str;

        cin >> str;

        len = str.length();

        for (int i = 0; i < len; i++)
        {
            alpha[str[i] - 'a']++;
        }

        mix("", 0);
    }
    return 0;
}