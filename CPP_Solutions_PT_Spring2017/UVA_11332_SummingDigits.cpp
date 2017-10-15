#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	ull input;
	int sum;

	while (cin >> input && input != 0)
	{
		bool found = false;
		sum = 0;
		while (!found)
		{
			while (input != 0)
			{
				sum += input % 10;
				input /= 10;
			}
			input = sum;
			sum = 0;
			
			if (input < 10)
				found = true;

		}
		cout << input << endl;

	}


	return 0;

}
