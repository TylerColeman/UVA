#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	vector<int>table(255, 0);
	int startLC = 97;
	int startUC = 65;
	for (int i = 1; i <= 26; i++)
	{
		table[startLC] = i;
		table[startUC] = i;
		startLC++;
		startUC++;
	}
	string n1, n2;
	int sumN1, sumN2;
	int sumDigitsN1, sumDigitsN2;
	while (getline(cin, n1) && getline(cin, n2))
	{
		sumN1 = sumN2 = 0;
		sumDigitsN1 = sumDigitsN2 = 0;
		for (int i = 0; i < n1.size(); i++){ sumN1 += table[n1[i]]; }
		for (int i = 0; i < n2.size(); i++) { sumN2 += table[n2[i]]; }
		bool valid = false;
		bool validN1, validN2;
		validN1 = validN2 = false;
		while (!valid)
		{
			while (sumN1 > 0)
			{
				sumDigitsN1 += sumN1 % 10; sumN1 /= 10;
			}
			if (sumDigitsN1 > 9)
			{
				sumN1 = sumDigitsN1;
				sumDigitsN1 = 0;
			}
			else
			{
				validN1 = true;
			}
			while (sumN2 > 0) 
			{ 
				sumDigitsN2 += sumN2 % 10; sumN2 /= 10; 
			}
			if (sumDigitsN2 > 9)
			{
				sumN2 = sumDigitsN2;
				sumDigitsN2 = 0;
			}
			else
			{
				validN2 = true;
			}
			if (validN1 && validN2)
			{
				valid = true;
			}
		}
		float ratio;
		if (sumDigitsN1 > sumDigitsN2)
		{
			ratio = float(sumDigitsN2) / sumDigitsN1 * 100;
		}
		else
		{
			ratio = float(sumDigitsN1) / sumDigitsN2 * 100;
		}

		cout << fixed << setprecision(2) << ratio << " %" << endl;


	}


	return 0;
}