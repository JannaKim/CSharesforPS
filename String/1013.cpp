#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		string a;

		cin >> a;

		int idx = 0;

		while (1)
		{
			if (idx < a.length())
			{
				if ((a[idx] == '1' && a[idx + 1] == '0' && a[idx + 2] == '0'))
				{
					idx += 3;
					while (a[idx] == '0')
					{
						idx++;
					}

					if (a[idx] == '1')
					{
						while (a[idx] == '1')
						{
							idx++;
						}
					}
					else
					{
						cout << "NO" << endl;
						break;
					}
				}
				else if(idx > -1 && a[idx - 2] == '1' && a[idx - 1] == '1' && a[idx] == '0' && a[idx + 1] == '0')
				{
					idx += 2;
					while (a[idx] == '0')
					{
						idx++;
					}

					if (a[idx] == '1')
					{
						while (a[idx] == '1')
						{
							idx++;
						}
					}
					else
					{
						cout << "NO" << endl;
						break;
					}
				}
				else if (idx > 0 && a[idx - 1] == '1' && a[idx] == '0' && a[idx + 1] == '1')
				{
					idx += 2;					
				}
				else if (idx == 0 && a[0] == '0' && a[1] == '1')
				{
					idx += 2;
				}
				else
				{
					cout << "NO" << endl;
					break;
				}
			}
			else
			{
				cout << "YES" << endl;
				break;
			}
		}
	}
	return 0;
}