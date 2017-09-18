//
/* Tyler Coleman:  UVA Problem #673 Parentheses Balance: UVA username: Hackerman

	Data structure Used: stack

	tricks of the trade: Fairly straight forward problem, just push
						 the characters onto the stack as long as they
						 are left side chars. WHen a right side char is
						 found start checking to see if your current top
						 is the opposite side of your current char.
*/
//
#include<iostream>
#include<stack>
#include<string>

#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int data;
	string word;


	cin >> data;
	cin.ignore();

	for (int i = 0; i < data; i++)
	{
		stack<char> parentheses;

		bool balanced = true;
		getline(cin, word);


		//empty string is a good case
		if (word.empty())
		{
			balanced = true;
		}

		//non-empty string
		else
		{
			for (int j = 0; j < word.size(); j++)
			{

				//if the in put is a left character push on to stack
				if (word[j] == '(' || word[j] == '[')
				{
					parentheses.push(word[j]);
				}

				//we found a right character
				else
				{
					//if it matches the top char on the stack, pop it off.
					if (!parentheses.empty() && word[j] == ')' && parentheses.top() == '(')
					{
						parentheses.pop();
					}
					else if (!parentheses.empty() && word[j] == ']' && parentheses.top() == '[')
					{
						parentheses.pop();
					}

					//it doesn't match the top of the stack, thereby giving us a bad case.
					//making this an "else if" instead of an "else" will skip over blank spaces in
					//the input.
					else if (word[j] == ']' || word[j] == ')')
					{
						balanced = false;
					}
				}

			}

			//if the stack is empty, we have a good case.
			if (!parentheses.empty())
			{
				balanced = false;
			}
		}



		if (balanced)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}

	return 0;
}
