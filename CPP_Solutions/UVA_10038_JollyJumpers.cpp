//*****************************************************************
//              Project #2 Jolly Jumper
//                    Name: Tyler Coleman
//   CMPS 3013-101 Adv. Structures & Algorithms Date: 09-08-2016
//*****************************************************************
//This Program reads in a number indicating the length of a sequence
//the sequence is then tested to see if it is a "Jolly Jumper"
//meaning:the absolute values of the difference between
//successive elements take on all the values 1 through n ? 1.
//*****************************************************************


//I have written the entire program as turned in and have not copied 
//this code, or parts of this code from the internet or another student.  
//
//Signature____________________


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	bool jolly;
	int x;
	int vec_count;
	int data;

	//Vector to hold the sequence of numbers.
	vector<int> nums;

	//Vector to hold the differences of 
	//subsequent numbers in the vector.
	vector<int> difference;

	//Loop while we can read in values.
	while (cin >> data)
	{
		//reset thw count, flag, and vectors after
		//jolly jumper test.
		jolly = true;
		vec_count = 0;
		nums.clear();
		difference.clear();

		//loading the nums vector with the sequence 
		//of numbers and incrementing count.
		for (int i = 0; i < data; i++)
		{
			cin >> x;
			nums.push_back(x);
			vec_count++;
		}
		//loading another vector with the differences 
		//in our numbers in the "nums" vector.
		for (int j = 0; j < vec_count; j++)
		{
			if (j < vec_count - 1)
				difference.push_back(abs(nums[j] - nums[j + 1]));
		}

		//sorting the differences vector in ascending order.
		sort(difference.begin(), difference.end());

		//For the sequence to be Jolly the differences vector
		//must look like 1,2,3,4,5...n-1 
		//This code checks to see if each indes in the
		//vector is ascending by 1 starting with 1 all the 
		//way to n.
		for (int z = 0; z < vec_count - 1; z++)
		{
			if (difference[z] != z + 1)
				jolly = false;

		}


		if (jolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

	}

	return 0;
}

//Tyler Coleman:  UVA problem #10038  Jolly Jumpers:  UVA username: Hackerman

//Data structure required : Vectors

//Tricks of the trade :N/A

/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	bool jolly;
	int x;
	int vec_count;
	int data;

	//Vector to hold the sequence of numbers.
	vector<int> nums;

	//Vector to hold the differences of 
	//subsequent numbers in the vector.
	vector<int> difference;

	//Loop while we can read in values.
	while (cin >> data)
	{
		//reset the count, flag, and vectors after
		//jolly jumper test.
		jolly = true;
		vec_count = 0;
		nums.clear();
		difference.clear();
		vector<bool> isJolly(3000, false);


		//loading the nums vector with the sequence 
		//of numbers and incrementing count.
		for (int i = 0; i < data; i++)
		{
			cin >> x;
			nums.push_back(x);
			vec_count++;
		}
		//loading another vector with the differences 
		//in our numbers in the "nums" vector.
		for (int j = 0; j < vec_count; j++)
		{
			if (j < vec_count - 1)
				difference.push_back(abs(nums[j] - nums[j + 1]));
		}


		//set all indicies in isJolly to true that were in the differences vector.
		for (int z = 0; z < vec_count - 1; z++)
		{
			isJolly[difference[z]] = true;
		}

		//check to see if all indicies up to vec_count are true
		//if so then the numbers are a jolly jumper.
		for (int k = 1; k <= vec_count - 1; k++)
		{
			if (isJolly[k] == false)
				jolly = false;
		}


		if (jolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

	}

	return 0;
}

