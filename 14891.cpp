#include <deque>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int k;
deque <int> gear[5];

void clockward(int i)
{
	int ele = gear[i].back();
	gear[i].pop_back();
	gear[i].push_front(ele);
	return;
}

void unclockward(int i)
{
	int ele = gear[i].front();
	gear[i].pop_front();
	gear[i].push_back(ele);
	return;
}

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int num;
			scanf("%1d", &num);
			gear[i].push_back(num);
		}
	}

	scanf("%d", &k);

	while (k--)
	{
		int choice, dir, odd, left, right;
		scanf("%d %d", &choice, &dir);

		odd = choice % 2;
		left = choice;
		right = choice;
		
		for (int i = choice; i > 1; i--)
		{
			if (gear[i - 1][2] != gear[i][6])
			{
				left--;
			}
			else
			{
				break;
			}
		}
		for (int i = choice; i < 4; i++)
		{
			if (gear[i][2] != gear[i + 1][6])
			{
				right++;
			}
			else
			{
				break;
			}
		}

		for (int i = left; i <= right; i++)
		{

			if (odd == i % 2)
			{
				if (dir == 1)
				{
					clockward(i);
				}
				else
				{
					unclockward(i);
				}
			}
			else
			{
				if (dir == 1)
				{
					unclockward(i);
				}
				else
				{
					clockward(i);
				}
			}
		}

	}

	int sum = 0;

	for (int i = 1; i <= 4; i++)
	{
		sum += pow(2, i - 1) * gear[i].front();
	}
	printf("%d", sum);
	return 0;
}