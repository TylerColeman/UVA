/*
	Tyler Coleman:  UVA Problem #11388 GCD LCM:  Username: Hackerman

	Data structured used:  N/A

	Tricks of the trade: I just had to think about the relation ship between
						 G and L. Once I understood that, I found a way to just use a
						 if/else block to test for cases and output good answers
						 according to the relationship of G and L: That is:

							GCD(a, b) * LCM(a, b) = G * L
							A * B = G * L
*/
#include<iostream>
#include<algorithm>

using namespace std;



int main()
{
	int data, g, l;

	cin >> data;
	for (int i = 0; i < data; i++)
	{
		cin >> g >> l;
		//if l is not divisible by g then the test fails
		if (l % g != 0) cout << "-1" << endl;
		//otherwise it is possible.
		else cout << g << " " << l << endl;
	}

	return 0;
}