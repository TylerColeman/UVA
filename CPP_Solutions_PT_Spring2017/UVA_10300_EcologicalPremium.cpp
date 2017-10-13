#include<iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int cases, farmers;
	unsigned long long sum, size, animals, envFriend;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> farmers;
		sum = 0;
		for (int j = 0; j < farmers; j++)
		{
			cin >> size >> animals >> envFriend;
			sum += size * envFriend;
		}
		cout << sum << endl;
	}

	return 0;
}