#include<iostream>
#include<math.h>
using namespace std;
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	int start, first, second, third;

	while (cin >> start >> first >> second >> third && start + first + second + third != 0)
	{
		int sum = 80;

		if (start < first) { sum += 40 - abs((first)-(start)); }
		else { sum += abs((first)-(start)); }
		sum += 40;
		if (first <= second) { sum += abs((first)-(second)); }
		else { sum += 40 - abs((first)-(second)); }
		if (second < third) { sum += 40 - abs((second)-(third)); }
		else { sum += abs((second)-(third)); }
		
		cout << sum * 9 << endl;
	}


	return 0;
}