#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

int main()
{
	int num[26] = { 0, };
	int data[26] = { 0, };
	int a = 0, b = 0, maxdata = 0, max = 0, cnt = 0, length = 0;
	char w[1000000];

	scanf("%s", &w);
	length = strlen(w);

	for (int i = 0; i < length; i++)
	{
		a = w[i];
		a -= 65;
		if (a >= 32)
		{
			a -= 32;
		}
		num[a]++;
	}
	for (int i = 0; i < 26; i++)
	{
		data[i] = i + 65;
	}

	for (int i = 0; i < 26; i++)
	{
		if (max < num[i])
		{
			max = num[i];
			maxdata = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (max == num[i])
		{
			cnt++;
		}
		if (cnt >= 2)
		{
			printf("?");
			return 0;
		}
	}
	printf("%c", maxdata + 65);
	return 0;
}
