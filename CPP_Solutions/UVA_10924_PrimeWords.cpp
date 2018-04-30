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
	if (n != 1)
		return bs[n];
	else
		return true;

}
int main()
{
	sieve(2000);
	vector<int>table(255, 0);
	int startLC = 97;
	int startUC = 65;
	for (int i = 1; i <= 26; i++)
	{
		table[startLC] = i;
		table[startUC] = i + 26;
		startLC++;
		startUC++;
	}
	string word;
	int sum;
	while (getline(cin, word))
	{
		sum = 0;
		for (int i = 0; i < word.size(); i++)
		{
			sum += table[word[i]];
		}
		if (isPrime(sum)) { cout << "It is a prime word." << endl; }
		else { cout << "It is not a prime word." << endl; }
	}
	return 0;
}