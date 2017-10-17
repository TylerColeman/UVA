#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
int getMedian(vector<int>);
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	vector<int> nums;
	int num;
	while (cin >> num)
	{

		nums.push_back(num);
		sort(nums.begin(), nums.end());
		cout << getMedian(nums) << endl;

	}
	return 0;
}

int getMedian(vector<int> vals)
{
	if (vals.size() % 2 == 0) { return (vals[vals.size() / 2] + vals[vals.size() / 2 - 1]) / 2; }
	else { return vals[vals.size() / 2]; }
}
