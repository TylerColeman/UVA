//////////////////////////////////////////////////////////////////////////
/*Tyler Coleman:   UVA Problem #401  Palindromes:  UVA username: Hackerman

  Data Structures used: Array (table) and string objects
  
  Tricks of the trade: I created a table in an array with possible 
					   Reverses of characters. Th next step was to
					   check each word's letters on opposite ends of
					   the word for palindrome and mirrored string 
					   properties. 
					   ****Had to make a special case for odd numbered
					   word sizes and words with just 1 letter.
					   to check the middle letter for the mirrored 
					   string property.*/
/////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>

using namespace std;
#define endl '\n'

int main()
{
	string reverseChars = "AEHIJLMOSTUVWXYZ12358";
	string reverses = "A3HILJMO2TUVWXY51SEZ8";
	char charSwap[128];

	//building the reverse char table.
	for (int i = 0; i < reverseChars.size(); i++)
	{
		charSwap[reverseChars[i]] = reverses[i];
	}

	bool palindrome = true;
	bool mirroredString = true;

	string word;

	while (cin >> word)
	{
		//reset booleans each pass
		palindrome = true;
		mirroredString = true;

		//check the word over for the 2 properties
		for (int i = 0; i < word.size() / 2; i++)
		{
			if (palindrome && word[i] != word[word.size() - (i + 1)])
				palindrome = false;
			if (mirroredString && word[i] != charSwap[word[word.size() - (i + 1)]])
				mirroredString = false;
			
		}

		//special case for odd numbered word sizes and single letter words.
		if (mirroredString && word.size() % 2 != 0)
		{
			if (word[word.size() / 2] != charSwap[word[word.size() / 2]])
				mirroredString = false;
		}

		if (palindrome && mirroredString)
			cout << word << " -- is a mirrored palindrome." << endl << endl;
		else if (palindrome)
			cout << word << " -- is a regular palindrome." << endl << endl;
		else if (mirroredString)
			cout << word << " -- is a mirrored string." << endl << endl;
		else
			cout << word << " -- is not a palindrome." << endl << endl;
	}

	return 0;
}