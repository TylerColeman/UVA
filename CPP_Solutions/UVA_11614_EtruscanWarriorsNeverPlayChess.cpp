#include<iostream>
#include<math.h>
using namespace std;

#define endl '\n'
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	ull warriors, tmpp, tmp, x;
	double rows, y;
	
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> warriors;
		
		//the reverse of a summation***
		rows = (sqrt(1 + (8 * warriors)) - 1) / 2;
		x = rows;
		y = rows + .5;

		if (rows < y) { tmp = rows; cout << tmp << endl; }
		else { tmp = rows + 1; cout << tmp << endl; }
	}



	return 0;
}