#define _CRT_SECURE_NO_WARNINGS

#include <deque>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

int dp[2000][2000] = { 0 };
int n, m, sum = 0;
using namespace std;
int num[2000] = { 0 };
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < n; i++)
	{
		dp[i][i] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (num[i] == num[i + 1])
		{
			dp[i][i + 1] = 1;
			dp[i + 1][i] = 1;
		}
	}
	for (int j = 2; j < n; j++)
	{
		for (int i = 0; i < n - j; i++)
		{
			if (num[i] == num[i + j])
			{
				dp[i][i + j] = dp[i + 1][i + j - 1];
			}
		}
	}
	scanf("%d", &m);

	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a - 1][b - 1]);
	}
}