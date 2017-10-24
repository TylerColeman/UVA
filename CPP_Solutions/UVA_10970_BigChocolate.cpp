#include<iostream>
using namespace std;
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int n, m;
	while (cin >> n >> m) { cout << n * m - 1 << endl; }
	return 0;
}