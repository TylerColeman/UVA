#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
	unordered_map<string, string> tranlation;
	vector<string> words = { "HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE" };
	vector<string> lang = { "ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN" };

	for (int i = 0; i < words.size(); i++)
	{
		tranlation[words[i]] = lang[i];
	}
	
	string input;
	int i = 1;
	while (cin >> input && input != "#")
	{
		if(tranlation[input] != "")
			cout << "Case " << i << ": " << tranlation[input] << endl;
		else
			cout << "Case " << i << ": UNKNOWN" << endl;
		i++;
	}

	return 0;
}