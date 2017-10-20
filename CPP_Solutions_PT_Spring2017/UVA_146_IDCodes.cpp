#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string input, successor;
	while (cin >> input && input != "#")
	{
		if (next_permutation(input.begin(), input.end())) { successor = input; }
		else { successor = "No Successor"; }
		cout << successor << endl;
	}


	return 0;
}