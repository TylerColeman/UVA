#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string sentence, reversed, word;
	
	while (getline(cin, sentence))
	{
		vector<string> words;

		int i = 0;
		while (i < sentence.size())
		{
			
			word = "";
			if (sentence[i] == ' ')
			{ 
				while (i < sentence.size() && sentence[i] == ' ') { word += sentence[i]; i++; } 
			}
			else
			{
				while (i < sentence.size() && sentence[i] != ' ') { word += sentence[i]; i++; }
			}
			words.push_back(word);
		}

		sentence = "";
		for (int i = 0; i < words.size(); i++) 
		{ 
			for (int j = words[i].size(); j >= 0; j--)
			{
				if(words[i][j] != '\0')
					cout << words[i][j];
			}
			
		}
		cout << endl;

		
	}
	return 0;
}