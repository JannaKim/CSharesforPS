#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string nam;
int t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int cnt = 0;
		cin >> nam;
		int len = nam.length();
		for (int j = 0, k = len - 1; j < k; j++, k--)
		{
			if (nam[j] == nam[k])
			{
				continue;
			}
			else if (nam[j + 1] != nam[k] && nam[j] != nam[k - 1])
			{
				cnt = 2;
				break;
			}
			else
			{
				int temp1 = 0, temp2 = 0;
				for (int l = j + 1, m = k; l < m; l++, m--)
				{
					if (nam[l] == nam[m])
					{
						continue;
					}
					else
					{
						temp1 = 1;
						break;
					}
				}
				for (int l = j, m = k - 1; l < m; l++, m--)
				{
					if (nam[l] == nam[m])
					{
						continue;
					}
					else
					{
						temp2 = 1;
						break;
					}
				}
				if (temp1 == 1 && temp2 == 1)
				{
					cnt = 2;
				}
				else
				{
					cnt = 1;
				}
				break;
			}
		}
		if (cnt == 0)
		{
			printf("0\n");
		}
		else if (cnt == 1)
		{
			printf("1\n");
		}
		else
		{
			printf("2\n");
		}
	}
}