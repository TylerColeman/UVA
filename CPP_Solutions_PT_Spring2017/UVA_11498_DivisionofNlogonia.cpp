//UVA Problem #11498 The Division of Nlogonia

#include<iostream>

using namespace std;
#define endl '\n'

int main()
{

	int data, x, y, x0, y0;

	while (cin >> data && data != 0)
	{
		cin >> x >> y;
		for (int i = 0; i < data; i++)
		{
			cin >> x0 >> y0;
			if (x0 == x || y0 == y)
				cout << "divisa" << endl;
			else if (x0 > x && y0 > y)
				cout << "NE" << endl;
			else if (x0 > x && y0 < y)
				cout << "SE" << endl;
			else if (x0 < x && y0 > y)
				cout << "NO" << endl;
			else if (x0 < x && y0 < y)
				cout << "SO" << endl;
		}
	}
	return 0;
}