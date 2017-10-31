#include<iostream>
#define endl '\n'

using namespace std;
typedef long long ll;
ll collatz(ll, ll);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	ll A, L, numTerms;
	int index = 1;
	while (cin >> A >> L && A > 0)
	{
		cout << "Case " << index << ": A = " << A << ", limit = " << L <<  ", number of terms = " << collatz(A,L) << endl;
		index++;
	}
	return 0;
}

ll collatz(ll A, ll L)
{
	int numTerms = 0;
	while (A <= L && A > 1)
	{
		if (A % 2 == 0) { A = A / 2; }
		else { A = (A * 3 + 1); }
		numTerms++;

	}
	if (A > L) { return numTerms; }
	else { return ++numTerms; }
	

	
}