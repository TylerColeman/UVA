#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	int people, budget, numHotels, weeks;
	int price, beds;
	int sum; 
	while (cin >> people >> budget >> numHotels >> weeks)
	{
		sum = 0;
		for (int i = 0; i < numHotels; i++)
		{
			cin >> price;
			for (int k = 0; k < weeks; k++)
			{
				cin >> beds;
				if (beds >= people)
				{
					int priceToStay = price * people;
					if (priceToStay < budget)
					{
						if (sum == 0) { sum = priceToStay; }
						else 
						{
							if((priceToStay < sum))
								sum = priceToStay;
						}
					}
				}
			}
		}
		if (sum == 0)
		{
			cout << "stay home" << endl;
		}
		else
		{
			cout << sum << endl;
		}

	}


	return 0;
}