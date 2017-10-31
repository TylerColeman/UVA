#include<iostream>
#include<string>


#define MINLETTER 65
using namespace std;

int main()
{
	int cases, trueNum;
	string input, newString, num;
	char letter;
	cin >> cases;
	for (int i = 1; i <= cases; i++)
	{
		cin >> input;
		newString = "";
		int j = 0; 
		while (j < input.size())
		{
			num = "";
			letter = input[j]; j++;
			while (j < input.size() && input[j] < MINLETTER)
			{
				num += input[j];
				j++;
			}
			//turns a string into an integer
			trueNum = stoi(num);
			for (int i = 0; i < trueNum; i++)
			{
				newString += letter;
			}
		}
		cout << "Case " << i <<": " << newString << endl;
	}


	return 0;
}