//Plus One on the Subset
#include <iostream>
#include <string>

using namespace std;

int main() 
{
  int t;
  cin>>t;

  int n;

  for(int i=0; i<t; i++)
  {
    cin>>n;
    int may, men;
    cin>>may;
    men=may;
    int aux;
    for(int j=1; j<n; j++)
    {
      cin>>aux;
      if(aux>may)
        may=aux;
      if(aux<men)
        men=aux;
    }
    cout<<may-men<<endl;
  }
}