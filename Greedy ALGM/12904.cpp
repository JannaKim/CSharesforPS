#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	while (1)
	{
		if (t.length() == s.length())
		{
			if (t == s)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
			break;
		}
		char a = t[t.length() - 1];

		t.pop_back();

		if (a == 'B')
		{
			reverse(t.begin(), t.end());
		}
	}
	return 0;
}