#include<iostream>
#include<iomanip>

using namespace std;
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int n, k, totCigs, cigs;
	int butts;

	while (cin >> n >> k)
	{
		totCigs = 0;
		butts = 0;
		cigs = 0;
		while (n > 0)
		{
			totCigs += n;
			butts += n;
			n = butts / k;
			butts %= k;
		}
		cout << totCigs << endl;


	}

	return 0;
}