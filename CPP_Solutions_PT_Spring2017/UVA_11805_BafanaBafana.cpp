#include<iostream>
#include<math.h>
using namespace std;

#define endl '\n'
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int cases, N, K, P;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> N >> K >> P;
		K = (K + P) % N;
		if (K == 0)
		{
			K = N;
		}
			

		
		cout << "Case " << i + 1 <<": " << K << endl;
		
	}


	return 0;
}