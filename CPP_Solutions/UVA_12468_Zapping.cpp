#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b && a != -1)
	{
		if (b > a)
		{
			if (b - a < (100 - b + a)) { cout << b - a << endl; }
			else { cout << (100 - b + a) << endl; }
		}
		else
		{
			if (a - b < (100 - a + b)) { cout << a - b << endl; }
			else { cout << (100 - a + b) << endl; }
		}
	}


	return 0;
}