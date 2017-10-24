#include<iostream>
using namespace std;

int main()
{
  int cases;
  unsigned long start, end;
  cin >> cases;
  for(int i = 1; i <= cases; i++)
  {
    cin >> start >> end;
    unsigned long sum = 0;
    for(int j = start; j <= end; j++)
    {
      if(j % 2 != 0) {sum += j;}
    }
    cout << "Case " << i << ": " << sum << endl;
  }
  
  return 0;
}