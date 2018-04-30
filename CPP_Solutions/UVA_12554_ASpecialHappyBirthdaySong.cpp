#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	string happy = "Happy";
	string bday = "birthday";
	string to = "to";
	string you = "you";
	string Ruj = "Rujia";
	vector<string> bdaySong;
	for (int i = 0; i < 4; i++)
	{
		if (i == 2)
		{
			bdaySong.push_back(happy);
			bdaySong.push_back(bday);
			bdaySong.push_back(to);
			bdaySong.push_back(Ruj);
		}
		else
		{
			bdaySong.push_back(happy);
			bdaySong.push_back(bday);
			bdaySong.push_back(to);
			bdaySong.push_back(you);
		}
		
	}
	int ppl;
	string person;
	vector<string>people;
	cin >> ppl;
	for (int i = 0; i < ppl; i++)
	{
		cin >> person;
		people.push_back(person);

	}
	int index = 0;
	int songIndex = 0;
	while (index < people.size())
	{
		if (songIndex == 16) { songIndex = 0; }
		cout << people[index] << ": " << bdaySong[songIndex] << endl;
		index++;
		songIndex++;
	}
	if (index == people.size() && songIndex < bdaySong.size())
	{
		while (songIndex < bdaySong.size())
		{
			if (index == people.size()) { index = 0; }
			cout << people[index] << ": " << bdaySong[songIndex] << endl;
			index++;
			songIndex++;
		}
	}
	return 0;
}