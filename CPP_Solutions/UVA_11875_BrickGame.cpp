#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define endl '\n'

typedef unsigned long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();

	int cases, numPlayers, player;
	cin >> cases;
	for (int i = 1; i <= cases; i++)
	{
		vector<int> players;
		cin >> numPlayers;
		for (int j = 1; j <= numPlayers; j++)
		{
			cin >> player;
			players.push_back(player);
		}

		cout << "Case " << i << ": " << players[players.size() / 2] << endl; 

	}

	return 0;
}
