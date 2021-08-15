#include <math.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
long long x, y, gap, t;
float distin;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> x >> y;

		gap = 2 * sqrt(y - x) - 1;

		distin = 2 * sqrt(y - x) - 1 - floor(2 * sqrt(y - x) - 1);

		if (distin > 0)
		{
			cout << floor(gap) + 1 << endl;
		}
		else
		{
			cout << floor(gap) << endl;
		}
	}
	return 0;
}
