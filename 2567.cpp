#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0,-1,0, 1 };

int ori[2][100];
int w[101][101];

int main()
{
	int num = 0, cnt = 0, pi = 0;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> ori[0][i] >> ori[1][i];
		for (int j = ori[1][i]; j < ori[1][i] + 10; j++)
		{
			for (int k = ori[0][i]; k < ori[0][i] + 10; k++)
			{
				if (w[k][j] == 1)
				{
					continue;
				}
				w[k][j] = 1;
			}
		}
	}

	for (int j = 0; j < 100; j++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (w[k][j] == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					if (w[k + dx[i]][j + dy[i]] == 0)
					{
						cnt++;
					}
				}
			}
		}
	}
	printf("%d", cnt);
}