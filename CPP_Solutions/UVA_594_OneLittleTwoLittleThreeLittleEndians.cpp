//
/*
	Tyler Coleman:   UVA Problem #594 One little, two little.... UVA Username:Hackerman
	
	Data structure used: Bitset.

	Tricks of the trade: Swapping bytes in a bit set is a little 
						 tricky. I found the best method was to 
						 use a var that shifted over 8 bits, or a byte
						 before each pass over an 8 bit portion of the
						 set.

						 Then using the (i % 8) the shift var could be
						 decremented efectively traversing each byte in 
						 reverse order.

						 Also negative conversions had to be handled with
						 a seperate case using 2s complement to extract the 
						 proper value from the bitset.

*/
//

#include<iostream>
#include<bitset>

using namespace std;
#define set_SIZE 32
int main()
{
	bitset<set_SIZE> x;
	bitset<set_SIZE> newX;
	int num;
	while (cin >> num)
	{
		x = num;
		int shift = 0;
		
		for (int i = 0; i < newX.size(); i++)
		{	
			//before each byte move the shift
			//var over 8 to start the next byte's 
			//swapping.
			if (i % 8 == 0)
			{
				shift += 8;
			}

			
			newX[newX.size() - shift + (i % 8)] = x[i];
		}

		//if the most sifnifiganet bit is a 1 then the
		//converted value is negative so I use 2's complement
		//to convert the stored value to it's actual value and 
		//append the negative sign.
		if (newX[newX.size() - 1])
		{
			newX.flip();
			cout << num << " converts to " << "-" << newX.to_ulong() + 1 << endl;
		}
		//new number is positive.
		else
			cout << num << " converts to " << newX.to_ulong() << endl;
	}
	return 0;
}