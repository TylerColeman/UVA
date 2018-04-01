#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define endl '\n'


//slow brute force method
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int cases;
	cin >> cases;
	int amplitude, frequency;
	for (int i = 0; i < cases; i++)
	{
		//each test case seperated by a new line so ignore it
		cin.ignore();
		cin >> amplitude >> frequency;
		//cout << amplitude << " " << frequency << endl;

		for (int j = 0; j < frequency; j++)
		{
			for (int k = 1; k <= amplitude; k++)
			{
				//upwards
				for (int l = 0; l < k; l++)
				{
					cout << k;
				}
				cout << endl;
			}
			for (int k = amplitude - 1; k > 0; k--)
			{
				//downwards
				for (int l = k; l > 0; l--)
				{
					cout << k;
				}
				cout << endl;
			}
			if(j != frequency - 1)
				cout << endl;
		}
		if(i != cases - 1)
			cout << endl;
	}
	return 0;
}