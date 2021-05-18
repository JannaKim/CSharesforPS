#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

int a[101];
int c[101];
int use[101] = { 0, };

int main()
{
	int cnt = 0, ma = -5, num = 0, cn = 0, n = 0, m = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < m; i++)
	{
		ma = -5;
		if (cnt < n)
		{
			if (use[a[i]] == 1)
			{
				continue;
			}
			c[cnt] = a[i];
			use[a[i]] = 1;
			cnt++;
		}
		else
		{
			if (use[a[i]] == 1)
			{
				continue;
			}
			else
			{
				for (int k = 0; k < n; k++)
				{
					int index = -7;
					for (int j = i + 1; j < m; j++)
					{
						if (c[k] == a[j])
						{
							index = j - i;
							break;
						}
					}
					if (ma < index)
					{
						ma = index;
						num = k;
					}
					if (index == -7)
					{
						num = k;
						break;

					}
				}
			}
			use[a[i]] = 1;
			use[c[num]] = 0;
			c[num] = a[i];
			cn++;
		}
	}
	printf("%d", cn);
}