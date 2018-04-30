#include<iostream>
#include<string>
#include<math.h>
using namespace std;
enum outcome {pass,fail};
int main()
{
	// Note this passed but will fail a few test cases do to floating point precision errors
	float  wellHeight,climbDistance, slideDistance, fatigueFactor;
	while (cin >> wellHeight >> climbDistance >> slideDistance >> fatigueFactor && wellHeight != 0)
	{
		outcome result;
		float climbProgress, fatigue;
		climbProgress = 0;
		fatigue = (fatigueFactor / 100) * climbDistance;
		bool stillGoing = true;
		int days = 1;
		while (stillGoing)
		{
			climbProgress += climbDistance;
			if (climbProgress > wellHeight)
			{
				result = pass;
				stillGoing = false;
			}
			else
			{
				climbProgress -= slideDistance;
				if (climbProgress < 0)
				{
					result = fail;
					stillGoing = false;
				}
				else
				{
					days++;
					climbDistance -= fatigue;
					if (climbDistance <= 0)
					{
						climbDistance = 0;
					}
				}
			}
		}
		if (result == pass)
		{
			cout << "success on day " << days << endl;
		}
		else
		{
			cout << "failure on day " << days << endl;
		}
	}
	return 0;
}