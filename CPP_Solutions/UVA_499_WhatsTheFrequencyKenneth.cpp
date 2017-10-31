#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main()
{

	//build ascii table
	vector<bool> asciiTable(256, false);
	for (int i = 'A'; i <= 'Z'; i++) { asciiTable[i] = true; }
	for (int i = 'a'; i <= 'z'; i++) { asciiTable[i] = true; }
	string input, output;
	char letter;
	int maxFreq;
	while (getline(cin, input))
	{
		vector<int> letterCounter(256, 0);
		output = "";
		maxFreq = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if (asciiTable[input[i]]) { letterCounter[input[i]]++; }
		}

		for (int i = 'A'; i <= 'z'; i++)
		{
			if (letterCounter[i] > maxFreq) 
			{ 
				output = "";
				maxFreq = letterCounter[i]; 
				output += i;
			}
			else if (letterCounter[i] == maxFreq) { output += i; }

		}
		cout << output << " " << maxFreq << endl;
	}

	return 0;
}