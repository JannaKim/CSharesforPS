#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

string cmd, parenthesis;
int T, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		deque <int> num;
		cin >> cmd >> n >> parenthesis;
		int len = parenthesis.length();
		int sum = 0;
		
		for (int i = 1; i < len; i++)
		{
			if (parenthesis[i - 1] == '[' && parenthesis[i] == ']')
			{
				break;
			}
			if (parenthesis[i] == ',' || parenthesis[i] == ']')
			{
				num.push_back(sum);
				sum = 0;
				continue;
			}
			sum *= 10;
			sum += parenthesis[i] - 48;
		}
		
		len = cmd.length();
		int q = 1;
		for (int i = 0; i < len; i++)
		{
			if (cmd[i] == 'R')
			{
				q *= -1;
				continue;
			}
			else if (cmd[i] == 'D')
			{
				if (num.empty())
				{
					cout << "error\n";
					q = 0;
					break;
				}
				if (q == 1)
				{
					num.pop_front();
				}
				else
				{
					num.pop_back();
				}
			}
		}
		len = num.size();
		if (num.size() == 0 && q != 0)
		{
			cout << "[]\n";
			continue;
		}
		if (q == 1)
		{
			cout << "[";
			for (int i = 0; i < len; i++)
			{
				cout << num[i];
				if (i == len - 1)
				{
					cout << "]\n";
				}
				else
				{
					cout << ",";
				}
			}
		}
		else if (q == -1)
		{
			cout << "[";
			for (int i = len - 1; i >= 0; i--)
			{
				cout << num[i];
				if (i == 0)
				{
					cout << "]\n";
				}
				else
				{
					cout << ",";
				}
			}
		}
	}
}
