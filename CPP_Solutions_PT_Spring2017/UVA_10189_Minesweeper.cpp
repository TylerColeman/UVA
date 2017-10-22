#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int n, m, newN, newM;
	char tmp;

	int count = 1;
	cin >> n >> m;
	while (m + n != 0)
	{
		//dims for the padded version of the minefield
		newN = n + 2; newM = m + 2;

		vector<vector<int>> mineField(newN);

		//pad the first row with m+2 flag values;
		for (int i = 0; i < newM; i++) { mineField[0].push_back(-2); }

		for (int i = 1; i < newN - 1; i++)
		{
			for (int j = 0; j < newM - 1; j++)
			{
				//pad the first element of each row with flag val
				if (j == 0) { mineField[i].push_back(-2); }
				else
				{
					cin >> tmp;
					if (tmp == '.') { mineField[i].push_back(0); }
					else { mineField[i].push_back(-10000); }
				}
				
			}
			//pad the last element of each row with flag val
			mineField[i].push_back(-2);
		}

		//pad the last row with m+2 flag values
		for (int i = 0; i < newM; i++) { mineField[newN - 1].push_back(-2); }


		for (int i = 1; i < mineField.size() - 1; i++)
		{
			for (int j = 1; j < mineField[i].size() - 1; j++)
			{
				//a mine is a large negative number so it should never be positive 
				//even if it gets incremented by being another mines neighbor
				if (mineField[i][j] < 0)
				{
					//increment all adjacent indicies
					mineField[i - 1][j - 1]++; mineField[i - 1][j]++; mineField[i-1][j+1]++; mineField[i][j+1]++;
					mineField[i+1][j+1]++; mineField[i+1][j]++; mineField[i+1][j-1]++; mineField[i][j-1]++;
				}
			}
		}

		cout << "Field #" << count << ":" << endl;
		for (int i = 1; i < mineField.size() - 1; i++)
		{
			for (int j = 1; j < mineField[i].size() - 1; j++)
			{
				if (mineField[i][j] < 0) { cout << '*'; }
				else { cout << mineField[i][j]; }	
			}
			cout << endl;
		}
		cin >> n >> m;
		if (n + m != 0) { cout << endl; }
		
		count++;
	}

	return 0;
}