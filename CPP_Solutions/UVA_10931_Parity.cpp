#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	
	int num, bin;
	while (cin >> num && num != 0)
	{
		vector<int> binNum;
		int parity = 0;
		while (num != 0)
		{
			if (num % 2 == 1) { parity++; }
			binNum.push_back(num % 2);
			num /= 2;
		}
		cout << "The parity of ";
		for (int i = binNum.size() - 1; i >= 0; i--){ cout << binNum[i]; }
		cout << " is " << parity << " (mod 2)." << endl;

	}


	return 0;
}
