/*
	Tyler Coleman: Uva #469 Wetlands of Florida: Username: Hackerman

	Data Structures used: Vector, string

	Tricks of the Trade: This problem required an algorithm to find the area of water
						 in a 2 dim. plane. I used a recursive aglorithm to count and
						 remove all w adjacent to the original and then those adjacent 
						 to them and so on. this yields the area of the body of water.
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
#define endl '\n'

int findWarea(vector<vector<char>>&, int, int);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int cases;
	string line;
	cin >> cases;
	//ignore blank space
	cin.ignore();
	cin.ignore();

	for (int i = 0; i < cases; i++)
	{
		vector<vector<char>> wetLands;
		//keeping a copy of the plot
		vector<vector<char>> wetLands2;

		//tmps used to pad the body of land with extra rows and columns 
		//to make the findWarea function cleaner
		vector<char> x;
		vector<char> y;
		getline(cin, line);

		//create extra row
		for (int k = 0; k <= line.size() + 1; k++){ x.push_back('L'); }
		//extra top row
		wetLands.push_back(x);
		wetLands2.push_back(x);

		//prepend and append an L to create an extra column on both  (padding)
		y.push_back('L');
		for (int j = 0; j < line.size(); j++){ y.push_back(line[j]); }
		y.push_back('L');
		wetLands.push_back(y);
		wetLands2.push_back(y);

		//while we grab lines that represent land and water
		while (getline(cin, line) && (line[0] == 'L' || line[0] == 'W'))
		{
			//same padding concept as above but for each line of the area
			y.clear();
			y.push_back('L');
			for (int j = 0; j < line.size(); j++)
			{
				y.push_back(line[j]);
			}
			y.push_back('L');
			wetLands.push_back(y);
			wetLands2.push_back(y);
		}

		//pad bottom row
		wetLands.push_back(x);
		wetLands2.push_back(x);

		int r = 0;
		int c = 0;
		int count = 0;

		//this section takes the integer pairs that are in string for and converts them to 2 seperate
		//integers, so they can be worked with.
		while (line[count] != ' '){ count++; }
		for (int i = 0; i < count; i++){ r += (line[i] - 48) * pow(10, count - (i + 1)); }
		for (int j = count + 1; j < line.size(); j++){ c += (line[j] - 48) * pow(10, line.size() - (j + 1)); }

		cout << findWarea(wetLands, r, c) << endl;
	
		//reset wetlands after each call of findWarea, because the
		//algorithm requires the original copy to be manipulated so it 
		//maintains its changed form through recursive calls.
		//Therefore we need to reset the body for each test case.
		wetLands = wetLands2;
		while (getline(cin, line) && line != "")
		{
			wetLands = wetLands2;
			r = c = count = 0;
			while (line[count] != ' '){ count++; }
			for (int i = 0; i < count; i++){ r += (line[i] - 48) * pow(10, count - (i + 1)); }
			for (int j = count + 1; j < line.size(); j++){ c += (line[j] - 48) * pow(10, line.size() - (j + 1)); }
			cout << findWarea(wetLands, r, c) << endl;
		}

		
		if(i < cases - 1)
			cout << endl;
	}


	return 0;
}


/*
Function: findWarea
Params: 2d vector representing land and water, int row, int column
returns: integer, the area of the body of water
*/
int findWarea(vector<vector<char>> &wetLands, int r, int c)
{
	if (wetLands[r][c] == 'L')
	{
		return 0;
	}
	//when we find a w, change it to L and call the function recursivly with every 
	//adjacent spot.
	else if (wetLands[r][c] == 'W')
	{
		wetLands[r][c] = 'L';
		return 1 + findWarea(wetLands, r + 1, c) + findWarea(wetLands, r - 1, c) +
			findWarea(wetLands, r, c + 1) + findWarea(wetLands, r, c - 1) +
			findWarea(wetLands, r + 1, c + 1) + findWarea(wetLands, r - 1, c - 1) +
			findWarea(wetLands, r + 1, c - 1) + findWarea(wetLands, r - 1, c + 1);
	}


}