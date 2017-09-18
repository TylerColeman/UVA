/*
	Tyler Coleman: UVA #13131 Divisors: Username: Hackerman

	Data Structures used: N/A

	Tricks of the trade: I used a straight forward brute force method 
						 on this problem. I just find each factor up to 
						 sqrt N and for each factor simultaniously calculate
						 the B in: Factor * B = N. then make specail checks to see
						 if both are not multiples of K and check if they are equal
						 to each other so we don't double count them in the summation.
*/
#include<iostream>

using namespace std;
typedef long long ll;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int cases;
	ll result, N, K;
	ll otherEnd;

	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		result = 0;
		cin >> N >> K;

		//loop up to the square root of N
		for (int i = 1; i <= int(sqrt(N)); i++)
		{
			//i is a divisor of N
			if (N % i == 0)
			{
				//i is not a multiple of K therefore we can 
				//use it in the sum of divisors
				if (i % K != 0)
				{
					result += i;
				}

				//calculate what i is multiplied by to yield N
				otherEnd = N / i;
				//make sure it is also not a multiple of K
				//but we must also check to see if it is equivelent to the 
				//current factor so we don't add it in twice to our sum.
				if (otherEnd != i && otherEnd % K != 0)
				{
					result += otherEnd;
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}
