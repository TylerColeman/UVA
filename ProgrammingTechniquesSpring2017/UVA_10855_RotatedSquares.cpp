//////////////////////////////////////////////////////////////////////

//Tyler Coleman:   UVA Problem #10855 Rotated Square: UVA Username: Hackerman

//Data structure required : 2D Vector (used to make the matrix)

/*Tricks of the trade : I wrote a sepereat function to rotate the square
						90 degrees. After that it was just a matter of vector
						indexing inside of my nested for loop cluster.

						Note:Always carefully check which loop variable
						you are indexing with. My main issue came from
						out of bounds run time errors because i indexed
						my smaller matrix with a variable that counted
						to the size of the larger matrix.
*/
/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;


void rotate90Degrees(vector<vector<char>> &square);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int x, y;
	char a;
	bool inside;


	while (cin >> x >> y && x + y != 0)
	{
		vector<vector<char>> bigSquare(x);
		vector<vector<char>> smallSquare(y);
		vector<int> rotates(4, 0);

		//build large square
		for (int i = 0; i < x; i++)
		{
			for (int k = 0; k < x; k++)
			{
				cin >> a;
				bigSquare[i].push_back(a);
			}
		}

		//build small square
		for (int i = 0; i < y; i++)
		{
			for (int k = 0; k < y; k++)
			{
				cin >> a;
				smallSquare[i].push_back(a);
			}
		}

	


		//case for every 90 degree rotate.
		for (int i = 0; i < 4; i++)
		{
			if (i >= 1)
				rotate90Degrees(smallSquare);


			//subscript for the large square Y axis
			for (int k = 0; k <= bigSquare.size() - smallSquare.size(); k++)
			{
				//subscript for the large square X axis
				for (int j = 0; j <= bigSquare[k].size() - smallSquare.size(); j++)
				{
					
					//if the top left corner matches between the 2 square
					//go into the test loops
					if (smallSquare[0][0] == bigSquare[k][j])
					{
						//assume it matches and set the boolean to false when it doesn't match
						inside = true;
						for (int x = 0; x < smallSquare.size(); x++)
						{
							for (int z = 0; z < smallSquare[x].size(); z++)
							{
								if (smallSquare[x][z] != bigSquare[k + x][j + z])
									inside = false;
							}

						}
						if (inside)
							rotates[i] += 1;

					}

				}

			}
			if (i < 3)
				cout << rotates[i] << " ";
			else
				cout << rotates[i];
		
		}		
		cout << endl;
	
	}


	return 0;
}
void rotate90Degrees(vector<vector<char>> &square)
{
	vector<char> newSquare;

	//load a linear vector with the values of the matrix
	//in a way that swaps rows and columns
	for (int i = 0; i <square.size(); i++)
	{
		for (int k = square.size() - 1; k >= 0; k--)
		{
			newSquare.push_back(square[k][i]);


		}
	}

	int z = 0;
	//load the new matrix with values from the linear vector.
	for (int i = 0; i < square.size(); i++)
	for (int j = 0; j < square[i].size(); j++)
	{
		square[i][j] = newSquare[z];
		z++;
	}


}
