//UVA Problem #11799 Horror Dash

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'

int main()
{

	int data, students, fastest, current;
	
	cin >> data;

	for (int i = 1; i <= data; i++)
	{
		cin >> students;
		fastest = 0;

		for (int k = 0; k < students; k++)
		{
			cin >> current;
			if (current > fastest)
				fastest = current;
		}
		cout << "Case " << i << ":" << " " << fastest << endl;
	}


	return 0;
}