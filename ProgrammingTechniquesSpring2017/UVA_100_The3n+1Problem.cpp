//UVA Problem #100 The 3n+1 Problem.
//
//Built a table with values
#include<iostream>
#include<vector>

using namespace std;
#define endl '\n'
#define MAX 1000000


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> cycles(MAX, 0);
	int n, cycle;
	unsigned long i, j, min, max;
	int largestCycle = 0;

	//building a table of cycles
	//where each index is the number of
	//cycles for that number.
	for (int i = 0; i < MAX; i++)
	{
		n = i;
		cycle = 0;
		while (++cycle &&  n > 1)
		{
			if (n % 2 == 0)
				n = n / 2;
			else
				n = 3 * n + 1;

		}
		cycles[i] = cycle;
	}


	while (cin >> i && cin >> j)
	{
		largestCycle = 0;
		if (i < j)
		{
			min = i;
			max = j;
		}

		else
		{
			min = j;
			max = i;
		}
		//both input values are too large for 
		//the 10000 bound. according to BrianFry's
		//input the program should output "Invalid input"
		//and terminate the program.
		if (min > MAX)
		{
			cout << i << " " << j << " " << "Invalid input" << endl;
			return 0;
		}

		//max is out of the range for the problem
		//so just loop from min to "MAX"
		else if (max > MAX)
		{

			for (int y = min; y <= MAX - 1; y++)
			{
				if (cycles[y] > largestCycle)
					largestCycle = cycles[y];
			}
			cout << i << " " << j << " " << largestCycle << endl;
		}

		//both values were in range so loop from 
		//min to max 
		else
		{
			for (int y = min; y <= max; y++)
			{
				if (cycles[y] > largestCycle)
					largestCycle = cycles[y];
			}

			cout << i << " " << j << " " << largestCycle << endl;
		}
	}


	return 0;
}