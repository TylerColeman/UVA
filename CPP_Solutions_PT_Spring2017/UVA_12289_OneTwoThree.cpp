#include<iostream>
#include<string>
using namespace std;

int main()
{
	string word;
	int cases;

	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> word;
		if (word.size() > 3) { cout << 3 << endl; }
		else if((word[0] == 'o' && word[1] == 'n') || (word[1] == 'n' && word [2] == 'e') || (word[0] == 'o' && word[2] == 'e')) { cout << 1 << endl; }
		else { cout << 2 << endl; }


	}

	return 0;
}