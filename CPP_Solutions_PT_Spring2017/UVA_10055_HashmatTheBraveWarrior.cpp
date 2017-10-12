#include<iostream>
#include<math.h>
using namespace std;
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long a, b;

	while (cin >> a >> b)
	{
		if(a - b < 0) { cout << b - a << endl; }
		else { cout << a - b << endl; }
	}

	return 0;
}