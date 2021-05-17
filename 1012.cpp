#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bat[50][50];
int ato[50][50];
int t, n, m, k, a, b;

void dfs(int x, int y) 
{
	for (int i = 0; i < 4; i++) {
		
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (yy >= 0 && yy < n && xx >= 0 && xx < m)
		{
			if (bat[xx][yy] && ato[xx][yy] == 0)
			{
				ato[xx][yy] = 1;
				dfs(xx, yy);
			}
		}
	}
}

int main()
{
	int num = 0, cnt = 0;
	scanf("%d", &t);


	while (num < t)
	{
		scanf("%d", &m);
		scanf("%d", &n);
		scanf("%d", &k);
		memset(bat, 0, sizeof(ato));
		memset(ato, 0, sizeof(ato));

		for (int i = 0; i < k; i++)
		{
			scanf("%d %d", &a, &b);
			bat[a][b] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (bat[j][i] == 1 && ato[j][i] == 0)
				{
					dfs(j, i);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
		num++;
	}
}