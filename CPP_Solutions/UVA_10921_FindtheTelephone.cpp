#include<iostream>
#include<string>
#include<vector>
#define MAXLETTER 97
using namespace std;

int main()
{
	string phoneWord, phoneNumber;
	vector<int> letterConverter(MAXLETTER + 1, -1);
	letterConverter[48] = 0+48;
	letterConverter[49] = 1+48;
	for (int i = 65; i < letterConverter.size(); i++)
	{
		if (i < 68) { letterConverter[i] = 2 + 48; }
		else if (i < 71) { letterConverter[i] = 3 + 48; }
		else if (i < 74) { letterConverter[i] = 4 + 48; }
		else if (i < 77) { letterConverter[i] = 5 + 48; }
		else if (i < 80) { letterConverter[i] = 6 + 48; }
		else if (i < 84) { letterConverter[i] = 7 + 48; }
		else if (i < 87) { letterConverter[i] = 8 + 48; }
		else if (i < 91) { letterConverter[i] = 9 + 48; }
		
	}
	while (getline(cin, phoneWord))
	{
		phoneNumber = "";
		for (int i = 0; i < phoneWord.size(); i++)
		{
			if (phoneWord[i] != '-') 
			{
				phoneNumber += letterConverter[phoneWord[i]];
			}
			else
			{
				phoneNumber += '-';
			}
			
		}
		cout << phoneNumber << endl;
	}

	return 0;
}