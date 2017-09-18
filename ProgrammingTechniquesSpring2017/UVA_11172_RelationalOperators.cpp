//////////////////////////////////////////////////////////////////////
/*
Tyler Coleman:   Relational Operator: UVA 11172  UVA username:Hackerman

Data structure required:  N/A

Tricks of the trade: N/A
*/
/////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;


int main()
{

	int data;
	long a, b;

	cin >> data;
	for (int i = 0; i < data; i++)
	{
		cin >> a >> b;
		if (a < b)
			cout << "<" << endl;
		else if (a > b)
			cout << ">" << endl;
		else
			cout << "=" << endl;
	}

	return 0;
}