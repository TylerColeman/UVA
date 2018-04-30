#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int cases;
	int lj1, lj2;
	cin >> cases;
	bool asc;
	bool valid;
	cout << "Lumberjacks:" << endl;
	for (int i = 0; i < cases; i++)
	{
		valid = true;
		cin >> lj1 >> lj2;
		if (lj1 > lj2) { asc = false; }
		else { asc = true; }
		lj1 = lj2;
		for (int j = 2; j < 10; j++)
		{
			cin >> lj2;
			if (asc)
			{
				if (lj2 < lj1) { valid = false; }
			}
			else
			{
				if (lj1 < lj2) { valid = false; }
			}
			lj1 = lj2;
		}
		if (valid) { cout << "Ordered" << endl; }
		else { cout << "Unordered" << endl; }
	}
	return 0;
}