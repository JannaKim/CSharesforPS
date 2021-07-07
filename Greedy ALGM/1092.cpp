#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;

int lapse = 0;

vector <int> limit_crane;
vector <int> cargo;

bool cmp(int i, int j)
{
	return j < i;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		limit_crane.push_back(a);
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		cargo.push_back(a);
	}

	sort(limit_crane.begin(), limit_crane.end(), cmp);
	sort(cargo.begin(), cargo.end(), cmp);

	if (limit_crane[0] < cargo[0])
	{
		cout << -1;
		return 0;
	}
	while (!cargo.empty())
	{
		for (int i = 0; i < n; i++)
		{
			int load_weight = limit_crane[i];
			int sum = 0;

			for (int j = 0; j < cargo.size(); j++)
			{
				if (load_weight >= cargo[j])
				{
					cargo.erase(cargo.begin() + j);
					if (cargo.size() == 0)
					{
						break;
					}
					break;
				}
			}
		}
		lapse++;
	}

	cout << lapse;
	return 0;
}
