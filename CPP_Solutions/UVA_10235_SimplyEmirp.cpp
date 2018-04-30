#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
ll sieveSize;
bitset<10000010> bs;
//will hold all prime numbers up to an upper bound defined in main.
vector<int> primes;
#define endl '\n'

//sieve of Erosthosines
void sieve(ll upperB)
{
	sieveSize = upperB + 1;

	//set bit set to all 1s efectivly assuming 
	//all numberss are prime until proven not.
	bs.set();
	//0 and 1 are no prime
	bs[0] = bs[1] = 0;

	//for every number between 2 and size
	for (ll i = 2; i <= sieveSize; i++)
		//if we have an assumed prime
		//we test it.
		if (bs[i])
		{
			//change all multiples of i starting at i^2 becuase all 
			//previous non primes were handled by earlier itterations
			//to 0 because we have proven that they are not primes.
			for (ll j = i * i; j <= sieveSize; j += i)
			{
				bs[j] = 0;
			}
			//fill the vector with the remaining numbers, all of which are prime.
			primes.push_back(int(i));
		}
}

//checks primality according to the bitset created in 
//the sieve function.
bool isPrime(ll n)
{

	return bs[n];

}
int reverseNum(int num)
{
	int newNum = 0;
	while (num != 0)
	{
		if (num > 9)
			newNum = (newNum + num % 10) * 10;
		else
			newNum += num % 10;
		num /= 10;
	}
	return newNum;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	sieve(1000001);
	int num;
	while (cin >> num)
	{
		if (!isPrime(num))
		{
			cout << num << " is not prime." << endl;
		}
		else
		{
			if (isPrime(reverseNum(num)) && num != reverseNum(num))
			{
				cout << num << " is emirp." << endl;
			}
			else
			{
				cout << num << " is prime." << endl;
			}
		}
	}
	return 0;
}