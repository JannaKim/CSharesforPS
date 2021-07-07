#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector <long long> bucket;

long long result = 0;
int visit[10000] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		bucket.push_back(a);
	}

	sort(bucket.begin(), bucket.end());

	if (bucket.size() == 1)
	{
		cout << bucket[0];
		return 0;
	}

	for (int i = bucket.size() - 1; i > 0; i--)
	{
		if (!visit[i])
		{
			if (bucket[i - 1] > 1)
			{
				visit[i] = 1;
				visit[i - 1] = 1;
				result += bucket[i] * bucket[i - 1];
			}
			else if (bucket[i] >= 1)
			{
				visit[i] = 1;
				result += bucket[i];
				break;
			}
		}
	}

	for (int i = 0; i < bucket.size(); i++)
	{
		if (!visit[i])
		{
			if (i < bucket.size() - 1 && bucket[i + 1] <= 0)
			{
				visit[i] = 1;
				visit[i + 1] = 1;
				result += bucket[i] * bucket[i + 1];
			}
			else
			{
				visit[i] = 1;
				result += bucket[i];
			}
		}
	}

	cout << result;
	return 0;
}
