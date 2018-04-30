#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num;
	
	while (cin >> num && num >= 0)
	{
		vector<int> newNum;
		while (num >= 3)
		{
			newNum.push_back(num % 3);
			num /= 3;
		}
		newNum.push_back(num % 3);
		for (int i = newNum.size() - 1; i >=0; i--)
		{
			cout << newNum[i];
		}
		cout << endl;
	}
	return 0;
}