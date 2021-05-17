#include <stdio.h>
#include <math.h>

int check(int a[10], int ch)
{
	int digit = 0;
	if (ch != 0)
		for (int i = 0; ch != 0; i++)
		{
			int mod = 0;
			mod = ch % 10;
			ch /= 10;
			digit++;
			for (int j = 0; j < 10; j++)
			{
				if (a[j] == mod)
				{
					return -1;
				}
			}
		}
	else if (ch == 0)
	{
		digit = 1;
		for (int j = 0; j < 10; j++)
		{
			if (a[j] == 0)
			{
				return -1;
			}
		}
	}
	return digit;
}
int main()
{
	int num = 0, digit = 0, n = 0, m = 0, temp = 0, min = 1000000, ch = 100, length = 0;
	int unbu[10];
	scanf("%d", &n);
	scanf("%d", &m);
	min = abs(100 - n);
	for (int i = 0; i < 10; i++)
	{
		unbu[i] = -5;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d", &unbu[i]);
	}

	for (int i = 0; i <= 1000000; i++)
	{
		length = check(unbu, i);

		if (length < 0)
		{
			continue;
		}
		temp = length + abs(n - i);

		if (min > temp)
		{
			min = temp;
		}
	}
	printf("%d", min);
}