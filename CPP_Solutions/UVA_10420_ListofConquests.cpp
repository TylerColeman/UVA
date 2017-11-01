#include<iostream>
#include<string>
#include<map>
using namespace std;
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	map<string, int> countries;
	string country, input;
	int cases;
	cin >> cases;
	cin.ignore();
	for(int i = 0; i < cases; i++)
	{
		getline(cin, input);
		int j = 0;
		country = "";
		while (j < input.size() && input[j] == ' ') { j++; }
		while (j < input.size() && input[j] != ' ') { country += input[j]; j++; }
		countries[country]++;
	}

	map<string, int>::iterator x1;
	x1 = countries.begin();
	while(x1 != countries.end())
	{
		cout << x1->first << " " << x1->second << endl;
		x1++;
	}
}