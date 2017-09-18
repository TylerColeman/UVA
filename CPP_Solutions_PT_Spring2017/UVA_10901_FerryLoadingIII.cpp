//////////////////////////////////////////////////////////////////
/*
	Tyler Coleman:  UVA Problem #10901 FerryLoading III 

	Data structure used: Vector, pair, queue

	tricks of the trade: It was just a matter of testing 
						 for every possible case and handling
						 it correctly. I used 2 queues to simulate
						 either side of the river.
*/
//////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;
enum side {LEFT,RIGHT};
#define endl '\n'


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int data, capacity, travelTime, cars;
	int carTime;
	string x;
	side side;

	cin >> data;
	for (int i = 0; i < data; i++)
	{
		side = LEFT;
		cin >> capacity >> travelTime >> cars;

		vector<int> carTimes(cars);
		pair<int, int> currentCar;
		queue<pair<int, int>> leftLine;
		queue<pair<int, int>> rightLine;
		int t, currentCapacity;


		//load the left and right queues with cars.
		for (int k = 0; k < cars; k++)
		{
			cin >> carTime >> x;

			//first = car wait time
			currentCar.first = carTime;

			//second = car position in the input file.
			//which will be the same in the output file
			currentCar.second = k;\

			if (x == "left")
				leftLine.push(currentCar);
			else
				rightLine.push(currentCar);
		}

		side = LEFT;
		t = currentCapacity = 0;




		//only cars waiting on the left side.
		if (!leftLine.empty() && rightLine.empty())
		{
			//there are cars to move
			while (!leftLine.empty())
			{
				//boat is on left side
				if (side == LEFT)
				{
					//cartime is greater than current time so boat waits wil that time
					if (leftLine.front().first > t)
					{
						t = leftLine.front().first;
					}
				}
				//boat is on right side.
				else
				{
					//if cartime > current time then the boat waits then must travel back.
					if (leftLine.front().first > t)
					{
						t = leftLine.front().first + travelTime;

					}
					//car was already waiting so boat travels back
					else
					{
						t += travelTime;
					}
				}

				//simulation of picking up available cars and carrying them back.
				while (!leftLine.empty() && currentCapacity < capacity && leftLine.front().first <= t)
				{
					currentCar = leftLine.front();
					carTimes[currentCar.second] = t + travelTime;
					leftLine.pop();
					currentCapacity++;
				}

				//increment travel time
				t += travelTime;
				//boat is now on other side.
				side = RIGHT;
				currentCapacity = 0;


			}

			//output the cars travel times in the order they 
			//were read in.
			for (int j = 0; j < carTimes.size(); j++)
			{
				cout << carTimes[j] << endl;

			}
		}

		//cars only waiting on right side.

		else if (leftLine.empty() && !rightLine.empty())
		{
			//there are cars to be picked up
			while (!rightLine.empty())
			{
				//right car time is greater than current time so must travel over when we notice him
				if (rightLine.front().first > t)
				{
					t = rightLine.front().first + travelTime;
				}
				//he was already waiting so we just go over and get him
				else
				{
					t += travelTime;
				}


				//simulation
				while (!rightLine.empty() && currentCapacity < capacity && rightLine.front().first <= t)
				{
					currentCar = rightLine.front();
					carTimes[currentCar.second] = t + travelTime;
					rightLine.pop();
					currentCapacity++;
				}
				t += travelTime;
				currentCapacity = 0;
			}

			//output the cars travel times in the order they 
			//were read in.
			for (int j = 0; j < carTimes.size(); j++)
			{
				cout << carTimes[j] << endl;

			}
		}

		else
		{
			//there are cars waiting on both sides.
			while (!leftLine.empty() && !rightLine.empty())
			{
				//boat is on the left side
				if (side == LEFT)
				{
					//left car arrives first or at the same time
					if (leftLine.front().first <= t || leftLine.front().first <= rightLine.front().first)
					{
						//if it arrives later than current time set current time to the new time
						if (leftLine.front().first > t)
						{
							t = leftLine.front().first;
						}

						//simulation
						while (!leftLine.empty() && currentCapacity < capacity && leftLine.front().first <= t)
						{
							currentCar = leftLine.front();
							carTimes[currentCar.second] = t + travelTime;
							leftLine.pop();
							currentCapacity++;
						}

						t += travelTime;
						//boat is now on right side.
						side = RIGHT;
						currentCapacity = 0;
					}
					//car on the right side arrived first.
					else
					{
						//it arrived later than the time.
						//so must wait til we notice it then travel over to it.
						if (rightLine.front().first > t)
						{
							t = rightLine.front().first + travelTime;
						}
						//it was already waiting so we just go over to it.
						else
						{
							t += travelTime;
						}

						//simulation
						while (!rightLine.empty() && currentCapacity < capacity && rightLine.front().first <= t)
						{
							currentCar = rightLine.front();
							carTimes[currentCar.second] = t + travelTime;
							rightLine.pop();
							currentCapacity++;
						}


						t += travelTime;
						//boat is now on left side.
						side = LEFT;
						currentCapacity = 0;

					}
						
					


				}
				//boat is on the right side
				else
				{
					//if there is a car on the right side that arrived before or at the same time
					if (rightLine.front().first <= t || leftLine.front().first >= rightLine.front().first)
					{
						//the car arrived later than the current time.
						if (rightLine.front().first > t)
						{
							t = rightLine.front().first;
						}

						//simulation
						while (!rightLine.empty() && currentCapacity < capacity && rightLine.front().first <= t)
						{
							currentCar = rightLine.front();
							carTimes[currentCar.second] = t + travelTime;
							rightLine.pop();
							currentCapacity++;
						}
						t += travelTime;
						//boat now on left side
						side = LEFT;
						currentCapacity = 0;
					}

					//there is a car on the left side that arrived first.
					else
					{
						//it arrived later than the currrent time.
						if (leftLine.front().first > t)
						{
							t = leftLine.front().first + travelTime;
						}
						//it was already waiting
						else
						{
							t += travelTime;
						}

						//simulation
						while (!leftLine.empty() && currentCapacity < capacity && leftLine.front().first <= t)
						{
							currentCar = leftLine.front();
							carTimes[currentCar.second] = t + travelTime;
							leftLine.pop();
							currentCapacity++;
						}

						t += travelTime;
						//boat is now on the right side.
						side = RIGHT;
						currentCapacity = 0;
					}
				
				

				}
			}



			//only cars on left side remain
			while (!leftLine.empty())
			{
				if (side == LEFT)
				{
					if (leftLine.front().first > t)
					{
						t = leftLine.front().first;
					}

				}
				else
				{
					if (leftLine.front().first > t)
					{
						t = leftLine.front().first + travelTime;

					}
					else
					{
						t += travelTime;
					}
				}


				while (!leftLine.empty() && currentCapacity < capacity && leftLine.front().first <= t)
				{
					currentCar = leftLine.front();
					carTimes[currentCar.second] = t + travelTime;
					leftLine.pop();
					currentCapacity++;
				}

				t += travelTime;
				side = RIGHT;
				currentCapacity = 0;

			}


			//only cars on the right side remain
			while (!rightLine.empty())
			{
				if (side == RIGHT)
				{
					if (rightLine.front().first > t)
					{
						t = rightLine.front().first;
					}
				}
				else
				{
					if (rightLine.front().first > t)
					{
						t = rightLine.front().first + travelTime;
					}
					else
					{
						t += travelTime;
					}
				}

				



				while (!rightLine.empty() && currentCapacity < capacity && rightLine.front().first <= t)
				{
					currentCar = rightLine.front();
					carTimes[currentCar.second] = t + travelTime;
					rightLine.pop();
					currentCapacity++;
				}
				t += travelTime;
				side = LEFT;
				currentCapacity = 0;
			}



			//output the cars travel times in the order they 
			//were read in.
			for (int j = 0; j < carTimes.size(); j++)
			{
				cout << carTimes[j] << endl;

			}

		}


		if (i < data - 1)
			cout << endl;
	
	}

	return 0;
}