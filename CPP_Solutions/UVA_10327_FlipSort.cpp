#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int bubbleSort(vector<int> arr)
{
	int flips = 0;
	int tmp;
	bool swap = true;
	bool flag;
	while (swap)
	{
		flag = false;
		for (int i = 0; i < arr.size() - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = true;
				flips++;
			}
		}
		if (!flag) { swap = false; }

	}
	return flips;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int num, val, flips;
	while (cin >> num)
	{
		vector<int> nums;
		flips = 0;
		for (int i = 0; i < num; i++)
		{
			cin >> val;
			nums.push_back(val);
		}
		flips = bubbleSort(nums);
		cout << "Minimum exchange operations : " << flips << endl;
	}
	return 0;
}