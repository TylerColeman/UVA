/*
	Tyler Coleman: Uva Problem #10589 Area: Uva Username: Hackerman

	Data Structures used: Pair, Vector

	Tricks of the Trade: Straight forward approach, the distance formula is used
						 to from the current point to each of the 4 corners of the square
						 if all 4 distances are less than the radius for the 4 circles then
						 the point is contained. After you have the proper number of contained 
						 points you just plug into the equations.
*/
#include<iostream>
#include<math.h>
#include<vector>
#include<iomanip>

using namespace std;
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	
	double numPoints, radius, numPointsContained;

	//the 4 corners of the sqaure
	pair<double,  double> pointA, pointB, pointC, pointD, newPoint;
	
	bool contained;
	double area, tmp;


	//Point A will always be (0,0) according to problem
	pointA.first = 0; pointA.second = 0;
	
	//while we have more than 0 points to read in
	while (cin >> numPoints >> radius && numPoints != 0)
	{
		//reset
		numPointsContained = 0;

		//set each point of the 4 corners of the square
		pointB.first = radius;  pointB.second = 0;
		pointC.first = radius; pointC.second = radius;
		pointD.first = 0; pointD.second = radius;

		//vector to hold the points
		vector<pair<double, double>> points;
		points.push_back(pointA);
		points.push_back(pointB);
		points.push_back(pointC);
		points.push_back(pointD);
		
	
		//for each point in the input
		for (int i = 0; i < numPoints; i++)
		{
			//assume it is in the shaded area
			contained = true;

			cin >> newPoint.first >> newPoint.second;

			//for all 4 corners
			for (int j = 0; j < points.size(); j++)
			{
				//distance formula
				tmp = sqrt(pow(points[j].first - newPoint.first, 2) + pow(points[j].second - newPoint.second, 2));
				//if the distance from a corner to the point is ever greater than the radius
				//of one of the circles the point is not within the shaded region
				if (tmp > radius)
				{
					contained = false;
				}
			}

			
			if (contained) { numPointsContained++; }

			
			/*cout << newPoint.first << " " << newPoint.second << endl;*/
		}

		//area formula given in the problem
		area = numPointsContained * radius * (radius / numPoints);
		cout << fixed << setprecision(5) << area << endl;
	}


	return 0;
}