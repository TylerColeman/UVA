/*
	Tyler Coleman: Uva Problem #543 Goldbach's Conjecture: Uva Username: Hackerman

	Data Structures used: Bitset, Vector

	Tricks of the Trade: This problem delt with finding sums of prime
						 numbers, meaning we needed to know all prime
						 numbers up to a certain bound to work with them
						 the seive of Erosthosines is an efficient algorithm 
						 for creating a list of primes which runs in approx O(nLg(n))
						 similar to sorting a large data set. After having the list
						 of primes, the rest was simple. I just itterated through my vector
						 of subtracting the first found prime and continueing through 
						 until i found the other half of the sumation. This method also 
						 found the largest range between the 2 added values which is what this
						 problem requested had there been more than 1 set of numbers whos sum 
						 was our given input.
*/

#include<iostream>
#include<vector>
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



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//bitset with primes up to 1000001
	sieve(1000001);

	int num, i;
	bool found;

	while (cin >> num && num != 0)
	{
		//reset i and found var
		i = 1;
		found = false;

		//while we have not found the pair whose sum is num

		while (!found && i < num)
		{
			//if (num - each prime in ascending order) is prime
			//we have found our sum of odd primes that creates num.
			if (isPrime(num - primes[i]))
			{
				cout << num << " = " << primes[i] << " + " << num - primes[i] << endl;
				found = true;
			}
			//move to the next prime.
			else
			{
				i++;
			}

		}

	}



	return 0;
}