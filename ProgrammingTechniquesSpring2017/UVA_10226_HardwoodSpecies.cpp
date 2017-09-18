/*
	Tyler Coleman:  UVA Problem #10226 Hardwood Species: Username: Hackerman

	Data structures used: map, pair.

	Tricks of the trade: Utilize the maps ability to be used to count the occurences 
						 of a certain key.
*/

#include<iostream>
#include<string>
#include<map>
#include<iomanip>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int cases;

	string tree;

	//bring in the cases then ignore to use getline, then ignore again to skip the blank line.
	cin >> cases;
	cin.ignore();
	cin.ignore();

	//will hold each current tree
	pair<string, int> item;
	int total;



	for (int i = 0; i < cases; i++)
	{
		map<string, int> treeList;
		total = 0;

		//there are trees to get
		while (getline(cin, tree))
		{
			//when there is an empty line 
			//break out of the while to start 
			//the next set of data
			if (tree.empty())
			{
				break;
			}

			else
			{
				//if the tree doesn't exist yet, put it in the map
				if (treeList.count(tree) > 0)
				{
					item.first = tree;
					item.second = 1;
					treeList.insert(item);
				}
				//increment the number of occurences of a tree that has been seen before.
				else
				{
					treeList[tree]++;
				}
				//increment total number of trees for each case
				total++;
			}
		}

		//var to hold percentage of each tree
		double percentage;
		//used to iterate over the map
		map<string, int>::iterator x1;
		x1 = treeList.begin();

		//start from beginning and calculate each trees percentage
		//the map is ordered so the output will be alphabetical automatically.
		while (x1 != treeList.end())
		{
			percentage = double(x1->second) / total * 100;
			cout << x1->first << " " << fixed << setprecision(4) << percentage << endl;
			x1++;

		}
		if (i < cases - 1)
			cout << endl;
	
	}


	return 0;
}