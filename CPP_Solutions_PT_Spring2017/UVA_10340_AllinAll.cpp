#include<iostream>
#include<string>

using namespace std;


int main()
{
	string word, encWord;

	while (cin >> word >> encWord)
	{
		int matches = 0;
		int j = 0;
		int i = 0;
		while (i < word.size() && j < encWord.size())
		{
			if (word[i] == encWord[j])
			{
				i++; j++; matches++;
			}
			else { j++; }
		}

		if (matches == word.size()) { cout << "Yes" << endl; }
		else { cout << "No" << endl; }
	}

	return 0;
}