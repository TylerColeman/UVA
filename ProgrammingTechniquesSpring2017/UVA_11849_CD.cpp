////////////////////////////////////////////////////////////////
/*
	Tyler Coleman:  Uva Problem #11849 CD:   UVA Username: Hackerman

	Data structure used: Sets

	Tricks of the trade: There is a nice built in function
						 that finds the intersection of 2 
						 sets in the stl. Just load the 2 
						 sets and it will find the intersection a
						 and load it into a 3rd set.
*/
////////////////////////////////////////////////////////////////
#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;

#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int s1, s2;
	int item;


	while (cin >> s1 && cin >> s2 && s1 + s2 != 0)
	{
		set<int> jack;
		set<int> jill;
		set<int> intersect;

		//load "jack's" set of cds
		for (int i = 0; i < s1; i++)
		{
			cin >> item;
			jack.insert(item);
		}
		//load "jill's" set of cds
		for (int k = 0; k < s2; k++)
		{
			cin >> item;
			jill.insert(item);
		}

		//an algorithm from the algorithm library that finds the intersection of 2 sets of
		//values in a container and puts them into a third container.
		set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(),
			std::inserter(intersect, intersect.begin()));

		//output the size of the intersect set because
		//that is the number of cds that are in common
		//between the 2.
		cout << intersect.size() << endl;


	}


	return 0;
}