#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define endl '\n'
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	ll a, b;
	int aDigit, bDigit;
	while (cin >> a >> b && a + b != 0)
	{
		int sum = 0;
		bool carry = false;
		while (a != 0 || b != 0)
		{
			aDigit = a % 10;
			bDigit = b % 10;
			if (carry)
			{
				if (aDigit + bDigit + 1 > 9)
				{
					carry = true;
					sum++;
				}
				else
					carry = false;
			}
			else
			{
				if (aDigit + bDigit > 9)
				{
					carry = true;
					sum++;
				}
				else
				{
					carry = false;
				}
			}
			a /= 10;
			b /= 10;
			
		}
		if (sum > 1)
			cout << sum << " carry operations." << endl;
		else if(sum)
			cout << sum << " carry operation." << endl;
		else
			cout << "No carry operation." << endl;
	}
	

	return 0;
}