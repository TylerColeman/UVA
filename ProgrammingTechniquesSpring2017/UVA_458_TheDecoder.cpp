//////////////////////////////////////////////////////////////////////

//Tyler Coleman:   UVA Problem #458  The Decoder: UVA Username: Hackerman

//Data structure required : String class objects

//Tricks of the trade : Just subtract 7 from each ascii value in 
//						 the entire string to break the code.

/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>

using namespace std;
#define endl '\n'

int main()
{
	string code;

	while (getline(cin, code))
	{
		//subtract 7 from the ascii value 
		//in each index of the string.
		for (int i = 0; i < code.size(); i++)
		{
			code[i] = code[i] - 7;
		}
		cout << code << endl;
	}
	
	return 0;
}