#include <iostream>

using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int time = 0; time < t; time++)
	{
		string a, b;

		cin >> a >> b;

		int a_alpha[26] = { 0 };
		int b_alpha[26] = { 0 };
		int flag = 0;

		for (int i = 0; i < b.length(); i++)
		{
			b_alpha[b[i] - 'a']++;
		}

		int i = 0;

		while (1)
		{
			flag = 0;

			if (i >= b.length())
			{
				a_alpha[a[i - b.length()] - 'a']--;
			}
			if (i < a.length())
			{
				a_alpha[a[i] - 'a']++;
			}
			else
			{
				flag = 1;
				break;
			}
			for (int num = 0; num < 26; num++)
			{
				if (a_alpha[num])
				{
				}
				if (a_alpha[num] != b_alpha[num])
				{
					flag = 1;
				}
			}
			if (!flag)
			{
				cout << "YES\n";
				break;
			}
			i++;
		}
		if (!flag)
		{
			continue;
		}
		cout << "NO\n";
	}
	return 0;
}