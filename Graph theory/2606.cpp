#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

int n, m;
int channel[100][100];
int ato[100] = { 0, };
int cnt = 0;
void dfs(int pos)
{
	for (int i = 1; i < n; i++)
	{
		if (channel[pos][i] == 1 && ato[i] == 0)
		{
			cnt++;
			ato[i] = 1;
			dfs(i);
		}
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	int a = 0, b = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		channel[a - 1][b - 1] = 1;
		channel[b - 1][a - 1] = 1;
	}
	ato[0] = 1;
	dfs(0);
	printf("%d", cnt);
}
