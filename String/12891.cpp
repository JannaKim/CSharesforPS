#include <iostream>

using namespace std;

string a;
int n, m;
int upper[4];

int trans(char mark)
{
	if (mark == 'A')
	{
		return 0;
	}
	else if (mark == 'C')
	{
		return 1;
	}
	else if (mark == 'G')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}


int main(void)
{
	int cnt = 0;

	cin >> n >> m >> a;

	for (int i = 0; i < 4; i++)
	{
		cin >> upper[i];
	}

	int index = 0;

	int alpha[4] = { 0 };

	while (n > index)
	{
		if (m <= index)
		{
			alpha[trans(a[index - m])]--;
		}
		if (index < a.length())
		{
			alpha[trans(a[index])]++;
		}
		else
		{
			break;
		}
		if (index >= (m - 1))
		{
			int flag = 0;
			for (int i = 0; i < 4; i++)
			{
				if (alpha[i] < upper[i])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				cnt++;
			}
		}
		index++;
	}

	cout << cnt;
	return 0;
}