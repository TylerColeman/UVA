#include<iostream>
#include<string>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	int donation, sum;
	string command;
	sum = 0;
	while (cin >> command)
	{
		if (command[0] == 'd') { cin >> donation;  sum += donation; }
		else { cout << sum << endl; }
	}

	return 0;
}