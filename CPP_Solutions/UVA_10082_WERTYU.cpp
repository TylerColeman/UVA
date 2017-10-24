
//////////////////////////////////////////////////////////////////////
/*
Tyler Coleman:   UVA Problem #10082 WERTYU  UVA username:Hackerman

Data structure required:  array

Tricks of the trade: Create a table of characters which is indexed by the 
					 ascii values of the encoded input. This can be used
					 for many type of decoding algorithms that only  use
					 the swapping of characters in strings.
*/
/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
using namespace std;


int main()
{
	string code;
	//How the keyboard is correctly laid out
	string good = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
	//what the input will consist of (No "QAZ`")
	string bad =  "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
	char decode[256];

	//fill the decode array with the proper ascii values which 
	//will be indexed by the bad ascii values.
	for (int i = 0; i < good.size(); i++)
	{
		decode[bad[i]] = good[i];
	}


	while (getline(cin, code))
	{
		for (int j = 0; j < code.size(); j++)
		{
			if (code[j] != 32)
				code[j] = decode[code[j]];
		}
		cout << code << endl;
	}

	return 0;
}
