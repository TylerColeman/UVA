#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int cases, students, grade;
  double avg, percent;
  cin >> cases;
  for(int i = 0; i < cases; i++)
  {
    vector<int> grades;
    vector<int> goodGrades;
    avg = 0;
    cin >> students;
    for(int j = 0; j < students; j++)
    {
      cin >> grade;
      grades.push_back(grade);
    }
    
    for(int k = 0; k < grades.size(); k++)
    {
      avg += grades[k];
    }
    avg /= grades.size();
    
    for(int z = 0; z < grades.size(); z++)
    {
      if(grades[z] > avg)
      {
        goodGrades.push_back(grades[z]);
      }
    }
    percent = goodGrades.size() / grades.size() * 100;
    
    cout << percent << endl;
    
  }
  return 0;
}