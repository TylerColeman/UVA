//
/*
	Tyler Coleman:  UVA Problem #11933 Splitting Numbers: Uva username: Hackerman

	Data structure used: Bitset.

	Tricks of the Trade: I Used a boolean to swap between the new
						 sets a and b. and if there was a 1 in the 
						 current position then a or b had a 1 placed 
						 in that position depending on the boolean.
*/
//

#include<iostream>
#include<bitset>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int num;



	while (cin >> num && num != 0)
	{
		bitset<32> n;
		bitset<32> a;
		bitset<32> b;

		n = num;
		//used to swap between bitset a and b
		bool swap = true;

		
		for (int i = 0; i < n.size()-1; i++)
		{   
			//set b[i] = n[i] at this position.
			if (swap && n[i])
			{
				b[i] = n[i];
				swap = false;
			}
			//set a[i] = n[i] at this position.
			else if (n[i])
			{
				a[i] = n[i];
				swap = true;
			}
		}

	
		cout << b.to_ulong() << " " << a.to_ulong() << endl;
	
	}


	return 0;
}