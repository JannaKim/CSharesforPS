#include <stdio.h>

int main()
{
	int sensor[10000];
	int gap[10000] = { 0, };
	int n = 0, k = 0, temp = 0, sum = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &sensor[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sensor[i] > sensor[j])
			{
				temp = sensor[i];
				sensor[i] = sensor[j];
				sensor[j] = temp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		gap[i] = sensor[i + 1] - sensor[i];
		sum += gap[i];
	}
	gap[n] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (gap[i] > gap[j])
			{
				temp = gap[i];
				gap[i] = gap[j];
				gap[j] = temp;
			}
		}
	}

	for (int i = 0; i < k; i++)
	{
		sum -= gap[n - i];
	}
	if (k >= n)
	{
		sum = 0;
	}
	printf("%d", sum);
}
