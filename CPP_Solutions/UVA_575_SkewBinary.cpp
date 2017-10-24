#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;
#define endl '\n'

typedef unsigned long long ll;
ll constructNum(vector<int> nums);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	ll num;
	string input;
	while (cin >> input && input != "0")
	{
		vector<int> vals;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '2') { vals.push_back(2); }
			else if (input[i] == '1') { vals.push_back(1); }
			else { vals.push_back(0); }
		}
		num = constructNum(vals);
		cout << num << endl;
	}

	return 0;
}

ll constructNum(vector<int> nums)
{
	ll num = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		num += nums[i] * (pow(2, (nums.size() - i)) - 1);
	}
	return num;
}