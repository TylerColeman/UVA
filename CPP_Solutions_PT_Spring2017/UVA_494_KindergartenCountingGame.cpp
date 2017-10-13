#include<iostream>
#include<string>
#include<vector>

using namespace std;

const string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	vector<bool> alphabet(256, false);
	string sentence;

	for (int i = 0; i < UPPERCASE.size(); i++)
	{
		alphabet[UPPERCASE[i]] = true;
		alphabet[LOWERCASE[i]] = true;
	}

	while (getline(cin, sentence))
	{
		bool finished = false;
		int index = 0;
		int sumWords = 0;
		while (!finished)
		{
			//loop until i find the start of the first word
			while (index < sentence.size() && !alphabet[sentence[index]]) { index++; }
			//still haven't seen the whole sentence
			while (index < sentence.size())
			{
				sumWords++;
				//loop until we finish the current word
				while (index < sentence.size() && alphabet[sentence[index]]) { index++; }
				//loop until the start of the next word
				while (index < sentence.size() && !alphabet[sentence[index]]) { index++; }
			}
			if (index == sentence.size()) { finished = true; }
		}
		cout << sumWords << endl;
	}


	return 0;
}