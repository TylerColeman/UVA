////////////////////////////////////////////////////////////////////////////
/* Tyler Coleman: UVA problem #514 Rails UVA username: Hackerman

	Data structures used: stack and queue

	Tricks of the trade: Load a queue with the current permutation 
						 of the train car order. Then, push on to 
						 the stack and compare to the front of the queue
						 when you find matching values, pop them off
						 both the stack and the queue.

						 If the stack (train station) has any cars remaining, then
						 the current permutation could not be achieved.
*/
/////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<stack>
#include<vector>
#include<queue>

#define endl '\n'
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int coach, numCoaches;
	

	while (cin >> numCoaches && numCoaches != 0)
	{
		//cout << numCoaches << endl;
		bool flag = true;
		
		while (flag)
		{
			while (cin >> coach)
			{
				//bool firstInstance = true;
				stack<int> station;
				queue<int> reordered;

				//break the loop if a 0 is read in to end this set of cases
				if (coach == 0)
				{
					flag = false;
					break;
				}


				else
				{
					//load the queue with the current permutation
					//of train cars.
					reordered.push(coach);
					for (int z = 1; z < numCoaches; z++)
					{
						cin >> coach;
						reordered.push(coach);
					}
				
						
					for (int x = 1; x <= numCoaches; x++)
					{
						//push on to the stack, then check the front
						//of the queue against the top of the stack 
						//and pop both if necessary.
						station.push(x);
						while (!station.empty() && !reordered.empty() && station.top() == reordered.front())
						{
							station.pop();
							reordered.pop();
						}
			
					}

				
					//if our stack still holds values, the current
					//permutation is impossible to achieve.
					if (station.empty())
						cout << "Yes" << endl;

					else
						cout << "No" << endl;
				}

			}

			cout << endl;
		}
	}
		
	return 0;
}