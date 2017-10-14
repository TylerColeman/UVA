#include<iostream>
#include<vector>

using namespace std;

#define endl '\n'

int bubbleSort(vector<int>, int);
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int cases, numCars, car, swaps;
	
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		vector<int> trainCars;
		cin >> numCars;
		for (int j = 0; j < numCars; j++)
		{
			cin >> car;
			trainCars.push_back(car);
		}
		swaps = bubbleSort(trainCars, trainCars.size());
		cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
	}
	
	return 0;
}

int bubbleSort(vector<int> train, int size)
{
	int tmp;
	int swaps = 0;
	bool swap = true;
	bool flag;
	while (swap)
	{
		flag = false;
		for (int i = 0; i < size - 1; i++)
		{

			if (train[i] > train[i + 1])
			{
				tmp = train[i];
				train[i] = train[i + 1];
				train[i + 1] = tmp;
				flag = true;
				swaps++;
			}

		}
		if (!flag)
		{
			swap = false;
		}
	}
	return swaps;
}