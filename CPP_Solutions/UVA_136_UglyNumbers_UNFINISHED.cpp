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


int main()
{
  sieve(1000001);

  vector<int> ugly;
  int num = 16;
  bool possible = false;
  while(ugly.size() < 1489)
  {
    int i = 3;
    if(num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {possible = true;}
    while(possible && i < num)
    {
      if (num % primes[i] == 0)
        possible = false;
      i++;
    }
    
    if(possible)
    {
      ugly.push_back(num);
    }
    num++;
  }
  cout << ugly[10];
  
  
  return 0;
}