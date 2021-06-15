#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int f, s, g, u, d;
int visit[1000001] = { 0 };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> f >> s >> g >> u >> d;

	queue <int> elevator;
	visit[s] = 1;
	elevator.push(s);
	while (!elevator.empty())
	{
		int floor = elevator.front();

		elevator.pop();

		int nextfloor = floor + u;

		if (nextfloor > 0 && nextfloor <= f && !visit[nextfloor])
		{
			visit[nextfloor] = visit[floor] + 1;
			elevator.push(nextfloor);
		}
		
		nextfloor = floor - d;

		if (nextfloor > 0 && nextfloor <= f && !visit[nextfloor])
		{
			visit[nextfloor] = visit[floor] + 1;
			elevator.push(nextfloor);
		}
	}
	if (visit[g] == 0)
	{
		cout << "use the stairs";
		return 0;
	}
	else
	{
		cout << visit[g] - 1;
		return 0;
	}
}