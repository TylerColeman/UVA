#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

//pythagorean theorem
int main()
{
	//sides
	unsigned long long a, b, c;
	while (cin >> a >> b >> c && a != 0)
	{
		//order the side lengths ascending
		int x = max(a, b);
		if (x > c) 
		{ 
			int tmp = c;
			c = x; 
			if (x == a) { a = tmp; }
			else { b = tmp; }
		}

		//square the sides
		a *= a; b *= b; c *= c;

		if (a + b == c) { cout << "right" << endl; }
		else { cout << "wrong" << endl; }
	}

	return 0;
}