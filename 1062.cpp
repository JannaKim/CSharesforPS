#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;

string st[51];
int al[26] = { 0, };
int n, k, ma;

void dfs(int ind, int cnt)
{
	if (cnt == k)
	{
		int cn = 0;
		for (int j = 0; j < n; j++)
		{
			int flag = 1;
			for (int i = 0; i < st[j].size(); i++)
			{
				if (al[st[j][i] - 'a'] == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				cn++;
			}
		}
		if (ma < cn)
		{
			ma = cn;
		}
		return;
	}

	for (int j = ind; j < 26; j++)
	{
		if (al[j] == 0)
		{
			al[j] = 1;
			dfs(j, cnt + 1);
			al[j] = 0;
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	al['a' - 'a'] = 1;
	al['n' - 'a'] = 1;
	al['t' - 'a'] = 1;
	al['i' - 'a'] = 1;
	al['c' - 'a'] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> st[i];
	}

	if (k < 5)
	{
		cout << "0";
	}
	else
	{
		k -= 5;
		dfs(0, 0);
		cout << ma;
	}
}