#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int cases, calls, call;
	int mile, juice;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		mile = juice = 0;
		cin >> calls;
		for (int j = 0; j < calls; j++)
		{
			cin >> call;
			if (call < 30) { mile += 10; }
			else
			{
				mile += 10 * (call / 30);
				if (call - (30 * (call / 30)) >= 0) { mile += 10; }
			}
			if (call < 60) { juice += 15; }
			else
			{
				juice += 15 * (call / 60);
				if (call - (60 * (call / 60)) >= 0) { juice += 15; }
			}

			
		}
		if (juice < mile) { cout << "Case " << i + 1 << ": Juice " << juice << endl; }
		else if (mile < juice) { cout << "Case " << i + 1 << ": Mile " << mile << endl; }
		else { cout << "Case " << i + 1 << ": Mile Juice " << juice << endl; }
	}
	return 0;
}