#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct info
{
	int bloomingDate;
	int fallingDate;
};

int n;

vector <info> flower;

bool cmp(struct info a, struct info b)
{
	return a.bloomingDate < b.bloomingDate;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		flower.push_back({ 100 * a + b, 100 * c + d });
	}

	sort(flower.begin(), flower.end(), cmp);

	int temp = 0;
	int cnt = 0;
	int end = 301;
	int index = -1;
	while (end < 1131 && index < n)
	{
		int flag = 0;
		index++;
		for (int i = index; i < n; i++)
		{
			if (flower[i].bloomingDate > end)
			{
				break;
			}
			if (flower[i].fallingDate > temp)
			{
				flag = 1;
				temp = flower[i].fallingDate;
				index = i;
			}
		}
		if (flag)
		{
			end = temp;
			cnt++;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}

	cout << cnt;
	return 0;
}