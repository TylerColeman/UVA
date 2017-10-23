#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, num;
	while (cin >> n && n != 0)
	{
		vector<int> vals;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			vals.push_back(num);
			
		}
		sort(vals.begin(), vals.end());
		cout << vals[0];
		for (int j = 1; j < vals.size(); j++) { cout << " " << vals[j]; }
		cout << endl;
	}

	return 0;
}
