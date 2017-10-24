#include<iostream>
#include<bitset>
using namespace std;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	bitset<32> a, b, c;
	int val1, val2;
	while (cin >> val1 >> val2)
	{
		a = val1;
		b = val2;

		for (int i = 0; i < c.size(); i++)
		{
			if ((a[i] && b[i]) || (!a[i] && !b[i])) { c[i] = 0; }
			else { c[i] = 1; }
		}
		cout << c.to_ulong() << endl;
	}


	return 0;
}