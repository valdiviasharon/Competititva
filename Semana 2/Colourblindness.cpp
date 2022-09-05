#include <iostream>
#include <string>

using namespace std;

int main() 
{
  int t;
  cin>>t;

  int n;
  string s1, s2;
  
  for(int i=0; i<t; i++)
  {
    cin>>n;
    cin>>s1;
    cin>>s2;
    bool legal = true;
    for(int j=0; j<n; j++)
    {
      if(s1[j] != s2[j])
      {
        if( (s1[j] == 'G' && s2[j] == 'B') ||
            (s1[j] == 'B' && s2[j] == 'G'))
          continue;
        else
        {
          legal = false;
          break;
        }
      }
    }
    if(legal)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
}

