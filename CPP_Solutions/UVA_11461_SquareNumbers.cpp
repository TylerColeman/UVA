#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<bool> squares(100001, false);

	//316 is the largest number that makes a square under 100000
	for (int i = 1; i < 317; i++)
	{
		squares[i * i] = true;
	}

	int a, b;
	while (cin >> a >> b && a + b != 0)
	{
		int count = 0;
		for (a; a <= b; a++)
		{
			if (squares[a])
				count++;
		}
		cout << count << endl;
	}

	return 0;
}