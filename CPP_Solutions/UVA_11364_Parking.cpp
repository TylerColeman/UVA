#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{

	int cases, stores;
	int input, max, min, parkingSpot;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		vector<int> nums;
		cin >> stores;
		for (int j = 0; j < stores; j++)
		{
			cin >> input;
			nums.push_back(input);
		}
		sort(nums.begin(), nums.end());
		cout << (nums[nums.size() - 1] - nums[0]) * 2 << endl;
	}

	return 0;
}