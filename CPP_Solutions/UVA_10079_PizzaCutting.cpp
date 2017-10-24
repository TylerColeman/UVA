#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long input;
	long long output;
	while (cin >> input && input >= 0)
	{
		//just a summation: n*(n+1) / 2
		cout << (long long)(input * (input + 1)) / 2 + 1 << endl;
	}

	return 0;
}