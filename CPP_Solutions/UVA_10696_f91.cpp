#include<iostream>
using namespace std;
#define endl '\n'

int f91(int);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int val, newVal;
	while (cin >> val && val != 0)
	{
		/*newVal = f91(val);*/
		if (val > 100)
			cout << "f91(" << val << ") = " << val - 10 << endl;
		else
			cout << "f91(" << val << ") = " << 91 << endl;
	}


	return 0;

}

int f91(int num)
{
	if (num >= 101)
		return num - 10;
	else
		return f91(num + 11);
}