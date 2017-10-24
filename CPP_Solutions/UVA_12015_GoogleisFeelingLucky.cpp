//////////////////////////////////////////////////////////////////////

//Tyler Coleman: UVA problem #12015 Google is Feeling Lucky:  UVA username: Hackerman

//Data structure required : Vectors

//Tricks of the trade :

/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main()
{

	int data;
	cin >> data;
	vector<string> urls;
	for (int i = 1; i <= data; i++)
	{
		cout << "Case #" << i << ":" << endl;
		//clear the vector after each data set and reset each var.
		urls.clear();
		int value = 0;
		string url;
		int largest = 0;
		for (int j = 0; j < 10; j++)
		{
			cin >> url >> value;
			//if the val is larger, clear the vector and put the new largest
			//in the vector.
			if (value > largest)
			{
				urls.clear();
				urls.push_back(url);
				largest = value;
			}
			//if the val is the same as the current largest
			//add that url to the vector.
			else if (value == largest)
				urls.push_back(url);
		}
		//output all current urls.
		for (int k = 0; k < urls.size(); k++)
			cout << urls[k] << endl;
	}


	return 0;
}