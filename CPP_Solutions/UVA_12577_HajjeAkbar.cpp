#include<iostream>
#include<string>
using namespace std;

const string HAJJ = "Hajj-e-Akbar";
const string UMRAH = "Hajj-e-Asghar";

int main()
{
	string input;
	int cases = 1;
	while (cin >> input && input != "*")
	{
		if (input == "Hajj") { cout << "Case " << cases << ": " << HAJJ << endl; }
		else { cout << "Case " << cases << ": " << UMRAH << endl; }
		cases++;
	}

	return 0;
}