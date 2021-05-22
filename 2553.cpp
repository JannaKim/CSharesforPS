#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

long long n = 0, sum = 1;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
		sum %= 10000000;
		while (sum % 10 == 0)
		{
			sum /= 10;
		}
	}
	cout << sum % 10;
}