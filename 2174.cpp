#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int a, b, n, m, ax, ay, f, entities;
char ff;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

struct robot
{
	int num;
	int x;
	int y;
	int dir; // 0 n, 1 e, 2 s, 3 w
};

vector<robot> robots;

void rotate(struct robot& r, char dir)
{
	if (dir == 'L')
	{
		r.dir--;
		if (r.dir < 0)
		{
			r.dir = 3;
		}
	}
	else
	{
		r.dir++;
		if (r.dir > 3)
		{
			r.dir = 0;
		}
	}
	return;
}

int forward(struct robot& r, int n)
{
	r.x += dx[r.dir];
	r.y += dy[r.dir];
	if (r.x > 0 && r.x <= a && r.y > 0 && r.y <= b)
	{
		for (int i = 0; i < entities; i++)
		{
			if (n == robots[i].num)
			{
				continue;
			}
			else
			{
				if (r.x == robots[i].x && r.y == robots[i].y)
				{
					cout << "Robot " << r.num << " crashes into robot " << robots[i].num;
					return 1;
				}
			}
		}
		return 0;
	}
	cout << "Robot " << r.num << " crashes into the wall";
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	cin >> n >> m;
	robot ro;
	for (int i = 0; i < n; i++)
	{
		cin >> ax >> ay >> ff;
		if (ff == 'N')
		{
			f = 0;
		}
		else if (ff == 'E')
		{
			f = 1;
		}
		else if (ff == 'S')
		{
			f = 2;
		}
		else
		{
			f = 3;
		}
		robot ro = {i + 1, ax, b - ay + 1, f};
		robots.push_back(ro);
	}

	entities = robots.size();

	for(int i = 0; i < m; i++)
	{
		int nums, d;
		char cmd;
		cin >> nums >> cmd >> d;
		for (int j = 0; j < entities; j++)
		{
			if (robots[j].num == nums)
			{
				for (int k = 0; k < d; k++)
				{
					if (cmd == 'F')
					{
						if (forward(robots[j], nums) == 1)
						{
							return 0;
						}

					}
					else
					{
						rotate(robots[j], cmd);
					}
				}
			}
		}
	}
	cout << "OK";
	return 0;
}