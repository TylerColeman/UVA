#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{

	int cases, numInstr;
	string instr;
	cin >> cases;
	int instIndex;
	for (int i = 0; i < cases; i++)
	{
		vector<string>instrList;
		instrList.push_back("");
		int p = 0;
		cin >> numInstr;
		cin.ignore();
		for (int j = 0; j < numInstr; j++)
		{

			getline(cin, instr);
			if (instr == "LEFT" || instr == "RIGHT")
			{
				instrList.push_back(instr);
				if (instr == "LEFT") { p--; }
				else { p++; }
			}
			else
			{
				int index = 8;
				instIndex = instr[index] - 48;
				index++;
				while (index < instr.size())
				{
					instIndex *= 10;
					instIndex += instr[index] - 48;
					index++;
				}
				if (instrList[instIndex] == "LEFT")
				{
					p--;
					instrList.push_back("LEFT");
				}
				else
				{
					p++;
					instrList.push_back("RIGHT");
				}
			}
			
		}
		cout << p << endl;
	}
	return 0;
}