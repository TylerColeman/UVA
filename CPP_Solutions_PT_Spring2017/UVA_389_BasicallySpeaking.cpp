/*
Tyler Coleman: Uva Problem #389 Basically Speaking: Uva Username: Hackerman

Data structures used: String, Vector

Tricks of the trade: Read the number in as a string and convert it to a base 10
					 integer using Horner's Rule for factoring a polynomial.

					 i.e (4*16^2 + 5*16^1 + 3*16^0) = ((4 * 16 + 5)16 + 3)

					 after having the base 10 integer, i used a loop to get the 
					 remainders of the division of the base 10 number and the new
					 base trying to be achieved. These values were stored in a character
					 vector and concatinated in reverse order into a string (as long as 
					 the number of elements was less than 7).
					 
					 **Note:I had to do this to allow for the output to be right justified 
					 which was one requirement of the problem. Otherwise i could have
					 just output each element of my vector in reverse order.
*/

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

#define endl '\n'
using namespace std;

//global ascii table vectors.
//built at start of main and used as 
//access only
vector<int> asciiTable(127, 0);
vector<char> invertedAsciiTable(127, 0);

//converts a string of character from 
//base {2,3,4,.....,16} to a base 10 integer.
int base10Converter(string, int);


int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	//build ascii table
	int l = 9;
	int h = -1;
	for (int i = '0'; i <= '9'; i++) { asciiTable[i] = ++h; }
	for (int j = 'A'; j <= 'F'; j++) { asciiTable[j] = ++l; }
	
	//build inverted ascii table
	int p = 65;
	int q = 48;
	for (int i = 0; i <= 9; i++) { invertedAsciiTable[i] = q++; }
	for (int j = 10; j <= 15; j++) { invertedAsciiTable[j] = p++; }


	string num, newNum, temp;

	int currentBase, newBase, tempNum;
	int tmp;
	
	//while there is input
	while (cin >> num >> currentBase >> newBase)
	{
		//vector to hold the final conversion from currentbase to newbase
		vector<char> finalConversion;
		newNum = "";

		//convert the num input string into a base 10 integer
		tempNum = base10Converter(num, currentBase);
		//tmp variable will be used to manipulate the value without changing it
		tmp = tempNum;

		//we have a base 10 integer so we just need to convert to the desired base
		//using integer division and the % operator to store the remainders of each 
		//division. This will yield a set of characters in reverse order.
		while (tmp / newBase > 0)
		{
			finalConversion.push_back(invertedAsciiTable[tmp % newBase]);
			tmp = tmp / newBase;
		}

		//have to push back the remaining value in tmp to account for
		//the "ones place" or newBase^0
		finalConversion.push_back(invertedAsciiTable[tmp]);

		//if the vectors capacity is greater than 7 elements
		//the value can not be displayed, so we have an error.
		if (finalConversion.size() > 7)
		{
			cout << setw(7) << "ERROR";
		}
	
		else
		{
			//concatinate the elements of the vector in reverse order to give us
			//a final converted string of characters.
			for (int i = finalConversion.size() - 1; i >= 0; i--)
			{
				newNum = newNum + finalConversion[i];
			}

			cout << setw(7) << newNum;
		}
	
		cout << endl;
		

	}


	return 0;
}


//Function:base10Converter

//Parameters: String object and integer

//Returns: Integer

/*Description: This function takes a string
object (that stands for a number) and the base
this number is currently in. Using Horner's Rule
the string is converted into a base 10 integer
*/
int base10Converter(string num, int base)
{
	string conv;
	int converted = 0;
	
	//only 1 element in the string
	//and element * base^0 = element.
	if (num.size() == 1)
	{
		converted = asciiTable[num[0]];
	}

	else
	{
		//Horners rule
		for (int i = 0; i < num.size() - 1; i++)
		{
			//first itteration
			if (i == 0){ converted = asciiTable[num[i]] * base + asciiTable[num[i + 1]]; }
			//every following itteration
			else { converted = (converted * base) + asciiTable[num[i + 1]]; }

		}
	}
	

	return converted;
}
