#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>

using namespace std;

char str[1000000];
char explo[36];
char arr[1000000];

int main()
{
	int stlen = 0, exlen = 0, cnt = 0, n = 0, flag = 0, temp = 0, index = 0;
	scanf("%s", str);
	scanf("%s,", explo);

	stlen = strlen(str);
	exlen = strlen(explo);
	for (int i = 0; i < stlen; i++)
	{
		arr[index++] = str[i];
		if (arr[index - 1] == explo[exlen - 1])
		{

			for (int j = exlen; j > 0; j--)
			{
				if (arr[index - j] == explo[exlen - j])
				{
					flag = 1;
				}
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 1)
		{
			for (int k = index - 1; k >= index - exlen; k--)
			{
				arr[k] = NULL;
			}
			index = index - exlen;
			cnt = 0;
			flag = 0;
		}
	}
	if (index == 0)
	{
		printf("FRULA");
	}
	printf("%s", arr);
}
