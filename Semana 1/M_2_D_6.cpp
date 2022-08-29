#include <iostream>

using namespace std;

int main() 
{
  int t,n;
  cin>>t;
  
  for(int i=0; i<t; i++)
  {
    cin>>n;
    if(n==1)
      cout<<0<<endl;
    else
    {
      int e_3=0, e_2=0;
      while(n%3==0)
      {
        e_3++;
        n/=3;
      }
      while(n%2==0)
      {
        e_2++;
        n/=2;
      }
      if(e_3>=e_2 && n==1)
        cout<<e_3 + (e_3-e_2)<<endl;
      else
        cout<<-1<<endl; //No se puede
    } 
  }
}