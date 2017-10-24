#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define endl '\n'

typedef unsigned long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int cases, N, tmp;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		vector<int> nums(10, 0);
		cin >> N;
		for (int j = 1; j <= N; j++)
		{
			tmp = j;
			while (tmp != 0)
			{
				nums[tmp % 10]++;
				tmp /= 10;
			}
		}
		cout << nums[0];
		for (int k = 1; k < nums.size(); k++) { cout << " " << nums[k]; }
		cout << endl;
	}

	return 0;
}
