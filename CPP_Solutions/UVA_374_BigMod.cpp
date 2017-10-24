////////////////////////////////////////////////////////////////
/*
Tyler Coleman:  UVA Problem 374 Big Mod: UVA Username: Hackerman

Data Structure used: N/A

Tricks of the trade: In the Competative programming book,
the Halim Brothers use a function that
does exponentation quickly (section 9.21). I took that code
and changed it to work wth our powermod problem
because it is a O(Lg(n)) function. The data set on
this problem was too large for a O(n) algorithm.
because the exponents could be as large as 2147483647.
*/
////////////////////////////////////////////////////////////////
#include<iostream>

using namespace std;
typedef long long ll;

//function that does the powermod algorithm
ll powMod(ll, ll, ll);

int main()
{
	ll b, p, m, r;

	while (cin >> b >> p >> m)
	{

		r = powMod(b, p, m);
		cout << r << endl;
	}

	return 0;
}

/*
Function: powMod
Return type: Long long
Description: This is a function written by the Halim's
that i took and changed to work with my current problem
powMod. 
*/
ll powMod(ll b, ll p, ll m)
{
	//exponent is 0
	if (p == 0) return 1 % m;
	//exponent is 1
	else if (p == 1) return b % m;
	//exponent > 1
	else
	{
		//recursive call that gives us our eventual 
		//exponent that we can work with.
		int res = powMod(b, p / 2, m);
		//square the res var
		res *= res;
		//if the expoenent was non even the we have to 
		//multiply by the bas value before moding
		if (p % 2 == 1)
			res = res * b % m;
		//otherwise we just have to mod with m.
		return res % m;
	}
}