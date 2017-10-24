//UVA Problem #11727 Cost Cutting

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define endl '\n'

int main()
{

	int data, s1, s2, s3;
	cin >> data;
	

	for (int i = 1; i <= data; i++)
	{
		vector<int> salaries;
		cin >> s1 >> s2 >> s3;
		salaries.push_back(s1);
		salaries.push_back(s2);
		salaries.push_back(s3);
		sort(salaries.begin(), salaries.end());

		cout << "Case " << i << ":" << " " << salaries[1] << endl;
	}
	return 0;
}