//UVA #272 Tex Quotes
#include<iostream>
#include<string>

using namespace std;

int main()
{

	string sentence;
	bool first;

	//read in lines
	first = true;
	
	while (getline(cin, sentence))
	{

		for (int i = 0; i < sentence.size(); i++)
		{

			//our first set of """
			if (first && sentence[i] == '"')
			{
				sentence[i] = '`';
				sentence.insert(i + 1, "`");
				first = false;
			}
			//second set of "
			else if (sentence[i] == '"')
			{
				sentence[i] = '\'';
				sentence.insert(i+1, "'");
				first = true;
			}

			
		}
	
		cout << sentence << endl;
		
	}


	return 0;
}