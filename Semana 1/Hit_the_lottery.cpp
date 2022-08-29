#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
  vector<int> dollars = {100,20,10,5,1};
  int dinero;
  cin>>dinero;
 
  int total=0;
 
  for(int i=0; i<dollars.size(); i++)
  {
    if(dinero/dollars[i]>0)
    {
      total += dinero/dollars[i];
      dinero = dinero%dollars[i];
    }
    if(dinero<=0)
    {
      cout<<total;
      break;
    }
  }
}