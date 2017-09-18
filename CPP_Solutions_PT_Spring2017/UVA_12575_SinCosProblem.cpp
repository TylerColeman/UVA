/*
Tyler Coleman:  Uva Problem #12575 SinCos Problem: Uva Username:Hackerman

Data structures used: N/A

Tricks of the trade: Understand Calculus and Trig!!!!!
Pythagorean Theorm finds the max val of the function.
Derivative finds the value of theta that yields the max.
if the theta turns out to be negative, you have to add
periods (2pi) until you get a positive theta.
*/

#include<iostream>
#include<math.h>
#include <iomanip>

using namespace std;

//problems definition for pi
#define pi acos(-1)

int main()
{
	int data;
	double a, b;
	double max, theta;

	cin >> data;
	for (int i = 0; i < data; i++)
	{
		cin >> a >> b;
		//We either have no sin value or no cos value
		if (a == 0 || b == 0)
		{
			//eqn is now:  F(theta)=ASin(theta)
			//cos part is zeroed.
			if (a != 0)
			{
				//max of the sin function
				max = sqrt(pow(a, 2));
				//sin is positive, so  its max val (1) occurs at theta = pi/2
				if (a > 0){ theta = pi / 2; }
				//sin is neg, so its max val (-1) occurs at theta = 3pi/2
				else{ theta = (3 * pi) / 2; }
			}

			//eqn is now: F(theta)=ACos(theta)
			//sin is zeroed out
			else if (b != 0)
			{
				//max of cos function
				max = sqrt(pow(b, 2));
				//cos is positive, so  its max val (1) occurs at theta = 0
				if (b > 0){ theta = 0; }
				//cos is negative, so its max val (-1) occurs at theta = pi
				else{ theta = pi; }
			}
			//both sin and cos are zeroed
			else
			{
				theta = 0;
				max = 0;
			}
		}

		//there is both a sin and cos value
		else
		{
			//pythagorean theorm for max of this function
			max = sqrt(pow(a, 2) + pow(b, 2));
			//after finding the derivative,  the theta that yields the max
			//value is found by Tan^-1(a / b)
			theta = atan2(a, b);
			//may be in the wrong quadrant to find the largest positive max
			//so add periods (i.e: 2pi) until we find our first positive value
			//of theta.
			while (theta < 0)
			{
				theta += 2 * pi;
			}
		}

		cout << fixed << setprecision(2) << theta << " " << max << endl;



	}


	return 0;
}