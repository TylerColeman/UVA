#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define endl '\n'
typedef long long ll;

ll constructNum(vector<int>);
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int cases, digit, count;
	ll p, reverseNum, tmp;
	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		bool palindrome = false;
		
		count = 0;
		cin >> p;
		int itter = 0;
		while (!palindrome)
		{
			vector<int> nums;
			tmp = p;
			while (tmp != 0)
			{
				digit = tmp % 10;
				nums.push_back(digit);
				tmp /= 10;
			}
			reverseNum = constructNum(nums);
			if (p == reverseNum && itter != 0)
			{
				cout << count << " " << p << endl;
				palindrome = true;
				
			}
				
			else
			{
				p += reverseNum;
				count++;
			}
			itter++;
		}

	}
	return 0;
}

ll constructNum(vector<int> nums)
{
	ll num = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		num += nums[i] * pow(10, nums.size() - (i+1));
	}
	return num;
}
