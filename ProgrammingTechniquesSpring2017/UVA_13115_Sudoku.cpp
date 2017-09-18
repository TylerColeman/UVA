/*
Tyler Coleman: Uva #13115 Sudoku: Username: Hackerman

Data Structures used: Vector, unordered map.

Tricks of the Trade: This problem delt with 2d vector indexing more than anything. 
					 It simply checks all rows, columns and root(n)Xroot(n) subsquares
					 for the unique values, 1 through n.
*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

#define MAX_SIZE 25
int main()
{
	//table to store square roots of our 2d array size
	vector<int> roots(MAX_SIZE + 1, 0);
	roots[4] = 2; roots[9] = 3; roots[16] = 4; roots[25] = 5;

	int data, n, tmp;
	cin >> data;

	for (int i = 0; i < data; i++)
	{
		//board size
		cin >> n;
		unordered_map<int, int> sudoku;
		vector<vector<int>> sudokuTable(n);
		//assume board is valid until proven false
		bool valid = true;


		//this loops simultaniously reads in the data and
		//validates each row.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> tmp;
				if (sudoku[tmp] == i)
				{
					sudokuTable[i].push_back(tmp);
					sudoku[tmp]++;
				}
				else
				{
					valid = false;
				}

			}
		}
		//all rows were valid
		if (valid)
		{
			sudoku.clear();
			//checks columns
			for (int row = 0; row < n && valid; row++)
			{
				for (int col = 0; col < n && valid; col++)
				{
					if (sudoku[sudokuTable[col][row]] == row)
					{
						sudoku[sudokuTable[col][row]]++;
					}
					else
					{
						valid = false;
					}
				}
			}
		}

		//both rows and columns were valis, check sub squares of the board
		//they will be root(n) X root(n) in size
		if (valid)
		{	
			//we have root(n) sub squares across
			for (int r = 0; r < roots[n] && valid; r++)
			{	//root(n) subsquares vertically
				for (int c = 0; c < roots[n] && valid; c++)
				{
					//reset for each sub square.
					sudoku.clear();
					for (int row = roots[n] * r; row < roots[n] + (roots[n] * r) && valid; row++)
					{
						for (int col = roots[n] * c; col < roots[n] + (roots[n] * c) && valid; col++)
						{
							if (sudoku[sudokuTable[row][col]] == 0)
							{
								sudoku[sudokuTable[row][col]]++;
							}
							else
							{
								valid = false;
							}
						}

					}
				}
			}
		}

		if (valid)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

	return 0;
}