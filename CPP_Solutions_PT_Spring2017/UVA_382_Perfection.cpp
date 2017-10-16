#include<iostream>
#include<iomanip>

using namespace std;
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int num;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> num && num != 0)
	{
		int sum = 0;
		for (int i = 1; i < num; i++)
		{
			if (num % i == 0)
			{
				sum += i;
			}
		}
		if (sum == num) { cout << setw(5) << num << "  " << "PERFECT" << endl; }
		else if (sum > num) { cout  << setw(5) << num << "  " << "ABUNDANT" << endl; }
		else { cout << setw(5) << num << "  " << "DEFICIENT" << endl; }
	}
	
	cout << "END OF OUTPUT" << endl;

	return 0;
}