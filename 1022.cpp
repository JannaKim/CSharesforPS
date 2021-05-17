#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

int num[400];

int ca(int r, int c)
{
	int n = -1;
	if (c == r && c <= 0)
	{
		n = (2 * c) * (2 * c) + 1;
	}
	else if (c == r && c > 0)
	{
		n = (2 * c + 1) * (2 * c + 1);
	}
	else if (abs(c) >= abs(r) && c < 0)
	{
		n = (2 * c) * (2 * c) + 1 + r - c;
	}
	else if (abs(c) < abs(r) && r > 0)
	{
		n = (2 * r) * (2 * r) + 2 * r + 1 + r + c;
	}
	else if (abs(c) > abs(r) && c > 0)
	{
		n = (2 * (c - 1) + 1) * (2 * (c - 1) + 1) + c - r;
	}
	else if (abs(c) <= abs(r) && r < 0)
	{
		n = (2 * r) * (2 * r) + (2 * (r + 1) - 1) - r - c;
	}
	return n;
}

int main()
{
	int c = 0, r = 0, n = 0, max = 0, len = 0;
	int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

	scanf("%d", &r1);
	scanf("%d", &c1);
	scanf("%d", &r2);
	scanf("%d", &c2);

	int a = 0;
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			num[a++] = ca(i, j);

			n = num[a - 1];

			while (num[a - 1] > 0) {
				num[a - 1] /= 10;
				len++;
			}

			num[a - 1] = n;

			if (max < len)
			{
				max = len;
			}

			len = 0;
		}
	}

	for (int i = 0; i < (c2 - c1 + 1) * (r2 - r1 + 1); i++)
	{
		int temp = num[i];
		int cnt = 0;

		while (num[i] > 0) {
			num[i] /= 10;
			cnt++;
		}
		num[i] = temp;
		for (int j = 0; j < max - cnt; j++)
		{
			printf(" ");
		}
		cnt = 0;
		printf("%d ", num[i]);
		if (i % (c2 - c1 + 1) == c2 - c1)
		{
			printf("\n");
		}
	}
}