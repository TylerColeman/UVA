#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int cases, walls, wall1, wall2, low, high;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		low = high = 0;
		cin >> walls;
		cin >> wall1;
		for (int j = 1; j < walls; j++)
		{
			cin >> wall2;
			if (wall1 > wall2) { low++; }
			else if (wall1 < wall2) { high++; }
			wall1 = wall2;
		}
		cout << "Case " << i + 1 << ": " << high << " " << low << endl;
	}
	return 0;
}