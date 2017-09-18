//////////////////////////////////////////////////////////////////////

//Tyler Coleman:   UVA Problem #11340 Newspaper: UVA Username: Hackerman

//Data structure required : Vector (used to make a table).

/*Tricks of the trade : for each data set, I made a table which
						held integer values and was indexed by
						a character ascii value. I then used the
						getline function to grab an entire line in
						the paragraph and itterated over it while 
						using an accumulator variable to add up
						the total cents the line was worth.

						***getline and cin did not play well together
						like Professor Simpson mentioned. I had to 
						watch carefully where i placed carriage returns
						in my program.
*/
/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;
#define endl '\n'

int main()
{
	//FAST
	ios_base::sync_with_stdio(false); cin.tie(0);

	int dataSets, numChars, charValue, articleLines, cents, dollars;
	char paidChars;
	string article;
	

	cin >> dataSets;

	for (int i = 0; i < dataSets; i++)
	{
		//create a size 256 vector and 0 it out.
		vector<int> chars(256, 0);
		//good
		cents = 0;
		dollars = 0;
		cin >> numChars;

		//build the table of character's monetary value.
		//if char not included in input file, a 0 is left 
		//in its place.
		for (int j = 0; j < numChars; j++)
		{
			cin >> paidChars >> charValue;
			chars[paidChars] = charValue;
		}


		
		cin >> articleLines;
		
		//for each line in the article, grab a line and itterate
		//over it while accumulating value in the cents var.
		for (int k = 0; k <= articleLines; k++)
		{
			getline(cin, article);
			
			for (int z = 0; z < article.size(); z++)
			{
				cents += chars[article[z]];
				
			}
		}

		//converts cents to Dollars and cents
		while (cents >= 100)
		{
		dollars += 1;
		cents -= 100;
		}

		//special case output to prepend the leading 0 to a single digit
		//integer like the problem required.
		if (cents < 10)
			cout << dollars << "." << setw(2) << setfill('0') << cents << "$" << endl;
		else
			cout << dollars << "." << cents << "$" << endl;
	}
	return 0;
}