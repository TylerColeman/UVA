/*
	Tyler Coleman: UVA Problem #13193 Rotations: Username: Hackerman

	Data Structures used: Bitset, unordered Map

	Tricks of the Trade: This problem could be dealt with in 2 ways Bit masking or bit set indexing. I chose to
						 use the bitset indexing approach, its a simple brute force algorithm that just aquires
						 all strings of consecutive 5 bits and converts them to an integer value and stores it. 
						 It must handle a wrap around case for the last sequences of 5 bits that go off the end of the 
						 bitset and wrap around to the bginning.
*/
#include<iostream>
#include<bitset>
#include<unordered_map>
using namespace std;

//working with 32 bit integers
const int SIZE = 32;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	unsigned int cases, value;
	unsigned long x;
	bitset<SIZE> numBinary;
	bitset<5> tmp;

	//will store each integer found int eh 5 bit sub strings and keep count of occurences
	unordered_map<unsigned long, int> range2;
	bool valid;

	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> value; numBinary = value;
		//assume the number meets the problems requirements
		valid = true;
		//clear the map for each iteration
		range2.clear();
		for (int j = 0; j < numBinary.size() && valid; j++)
		{
			for (int k = 0 + j; k < 5 + j; k++)
			{
				//this handles each set of 5 consecutive bits until the next 5 bits will need 
				//to wrap around to the other end of the bitset.
				if (k < numBinary.size()) { tmp.set(k - j, numBinary[k]); }
				//this handles the wrapping
				else{ tmp.set(k - j, numBinary[k - SIZE]); }
			}

			//convert each 5 bit number to a unsigned long
			//that we can store in the unordered map.
			x = tmp.to_ulong();
			range2[x]++;
			//if we ever find a duplicate value
			//then we can never have all values from 0 to 31
			//as 5 bit sub strings
			if (range2[x] > 1){ valid = false; }
		}

		if (valid)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

	return 0;
}
