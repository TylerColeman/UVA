#include<iostream>
using namespace std;

int main()
{
	int cases, event, sum;
	int j = 1;
	while (cin >> cases && cases != 0)
	{
		sum = 0;

		for (int i = 0; i < cases; i++)
		{
			cin >> event;
			if (event > 0) { sum++; }
			else { sum--; }
		}
		cout << "Case " << j << ": " << sum << endl;
		j++;
	}

	return 0;
}