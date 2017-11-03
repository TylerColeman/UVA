#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	vector<int> numers;
	vector<int> denoms;
	bool swapper = true;
	numers.push_back(1);
	denoms.push_back(1);
	//build list of numerators and denominators
	int j, k;
	for (int i = 2; i <= 4475; i++)
	{
		if (swapper)
		{
			j = 1;
			k = i;
			while (j <= i)
			{
				numers.push_back(j);
				j++;
			}
			while (k > 0)
			{
				denoms.push_back(k);
				k--;
			}
			swapper = false;
		}
		else
		{
			j = i;
			k = 1;
			while (j > 0)
			{
				numers.push_back(j);
				j--;
			}
			while (k <= i)
			{
				denoms.push_back(k);
				k++;
			}
			swapper = true;
		}

	}

	int num;
	while (cin >> num)
	{
		cout << "TERM " << num << " IS " << numers[num - 1]<< "/" << denoms[num - 1] << endl;
	}

	return 0;
}