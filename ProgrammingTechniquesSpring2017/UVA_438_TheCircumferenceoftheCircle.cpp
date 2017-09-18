/*
	Tyler Coleman: Uva Problem #438 The circumference of the circle: Username: Hackerman

	Data strucure used: N/A

	Tricks of the trade: The problem was understanding triangles and how to 
						 extract values like area without having a set shape

						 Taking the distance of the 3 points from each other 
						 gave the perimeter which was used to calculate the area
						 with Heron's formula. After finding area and perimeter
						 you can use a simple equation to find the radius of a 
						 circle that intersects all 3 points or a circumcircle.
						 and circumference of that circle is (2 * pi * r).
*/
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;


double distance(double, double, double, double);
#define pi 3.141592653589793

int main()
{

	//distances between the 3 points
	long double ab, bc, ac;

	//x and y vals of the points
	long double x1, y1, x2, y2, x3, y3;

	long double s, area, radius;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{

		//get the length of the sides of he triangles with 
		//the distance formula.
		ab = distance(x1, y1, x2, y2);
		bc = distance(x2, y2, x3, y3);
		ac = distance(x1, y1, x3, y3);

		//semi perimeter used in Heron's formula
		s = (ab + bc + ac) / 2;

		//area of the triangle found with heron's formula
		area = sqrt(s * (s - ab) * (s - bc) * (s - ac));

		//radius of the circumcircle of the 3 points.
		//formula found in The competative programming book.
		//page 280.
		radius = (ab * bc * ac) / (4 * area);


		//output 2 * pi * r = circumference of the circumcircle to the 3 points
		cout << fixed << setprecision(2) << 2 * pi * radius << endl;


	}
	return 0;
}

//distance between 2 points found using the distance formula.
double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}