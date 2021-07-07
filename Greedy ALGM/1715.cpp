#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, result = 0;

priority_queue <int> card;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        card.push(-num);
    }

    while (!card.empty())
    {
        if (card.size() == 1)
        {
            card.pop();
        }
        else
        {
            int a, b, c;
            a = -card.top();

            card.pop();

            b = -card.top();

            card.pop();
            
            c = a + b;

            result += c;

            card.push(-c);
        }
    }
    cout << result;
    return 0;
}
