/*
	Tyler Coleman:  UVA Problem #11286 Conformity: Username: Hackerman

	Data structures used: map, vector

	Tricks of the trade: The class numbers were placed into a vector, sorted, and
						 put into a string variable. a map was then indexed with
						 this string value and incremented after every ocurence of the same key.
						 The number of classes with the most popular totals were multiplied
						 by the number of times that they occured.
*/
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//number of classes
#define CLASS 5
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int data, classes;

	//most popular set of classes and the total number of those sets.
	int mostPopular, total;

	//holds our concatenated number 
	string s;



	while (cin >> data && data != 0)
	{

		//map will hold the total number of times a "key" value occurs
		map<string, int> popularity;
		
		//reset most popular and total
		mostPopular = 1;
		total = 1;

		for (int i = 0; i < data; i++)
		{
			
			vector<string> course(CLASS);
			s.clear();

			//put the 5 courses into a vector as strings
			for (int k = 0; k < CLASS; k++)
			{
				cin >> course[k];

			}
			//sort the vector
			sort(course.begin(), course.end());

			//concatenate the 5 sub strings into 1 string
			for (int j = 0; j < course.size(); j++)
			{
				s = s + course[j];
			}

			//if the key exists
			if (popularity.count(s) > 0)
			{
				//increment the number of occurences
				popularity[s]++;

				//there is more than just 1 occurence
				if (popularity[s] > 1)
				{
					//this set of classes is the current most popular
					if (popularity[s] > mostPopular)
					{
						mostPopular = popularity[s];
						total = 1;
					}

					//it has the same popularity as another set of classes
					//so now the total is 2.
					else if (popularity[s] == mostPopular)
					{
						total++;
					}
				}
				

			}
			//the combination of classes hasn't occured yet.
			else
			{
				popularity[s] = 1;
			}

		}

		if (mostPopular == 1)
		{
			cout << data << endl;
		}
		else
		{
			cout << mostPopular * total << endl;
		}



	}


	return 0;
}