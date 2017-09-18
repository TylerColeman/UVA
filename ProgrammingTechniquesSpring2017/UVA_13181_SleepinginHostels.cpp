/*
Tyler Coleman: Uva #13181 Sleeping in Hostels: Username: Hackerman

Data Structures used: string

Tricks of the Trade: Straightforward approach, just index down the string after it is read in
					 and calculate the distances from start->X->intermediate X's->end and output
					 the largest.
*/
#include<iostream>
#include<string>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	string row;
	int distance, maxDistance;
	bool moreXbeds;

	while (getline(cin, row))
	{
		//reset
		distance = 0;
		int i = 0;

		//distance from start to the first bed
		while (row[i] != 'X'){ distance++; i++; }
		//it will be the current max distance
		maxDistance = distance;

		//we hit the end of the string after seeing the first x (no more occupied beds)
		if (i == row.size() - 1)
			moreXbeds = false;
		//there will be more occupied beds
		else
			moreXbeds = true;
		
	
		while (moreXbeds)
		{
			//skip over the first x we found and reset the distance
			i++;
			distance = 0;

			//while we have not seen an occupied bed
			while (row[i] != 'X')
			{
				//we hit the end of the line with no occupied beds
				if (i == row.size() - 1)
				{
					moreXbeds = false;
					distance++;
					break;
				}

				distance++;
				i++;
				
			
			}
			
			//we are between 2 occupied beds
			if (moreXbeds)
			{
				if (distance % 2 == 0)
					distance = distance / 2;
				else
					distance = (distance / 2) + 1;
			}
			//we reached the end of the string on an occupied beds
			if (i == row.size() - 1)
				moreXbeds = false;


			if (distance > maxDistance)
			{
				maxDistance = distance;
			}
				

		}

		if (distance > maxDistance)
			cout << distance - 1 << endl;
		else
			cout << maxDistance - 1 << endl;


	}
	return 0;
}