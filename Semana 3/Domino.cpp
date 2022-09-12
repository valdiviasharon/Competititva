#include <iostream>

using namespace std;

#define ll long long int

int main() 
{
  ll n, m;
  
  cin>>n>>m;

  if(m==1)
    cout<<n-1<<endl;
  else
    cout<<(m-1)*n;
}