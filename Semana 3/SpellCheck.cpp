#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
  int t;
  cin>>t;

  while(t--)
  {
    int n;
    cin>>n;

    string s;
    cin>>s;
    if(s.find('T')==-1)
      cout<<"NO"<<endl;
    else
    {
      bool termino = false;
      vector<int>count(5,0);
      for(int i=0; i<n; i++)
      {
        if(s[i]=='T')
          count[0]++;
        else if(s[i]=='i')
          count[1]++;
        else if(s[i]=='m')
          count[2]++;
        else if(s[i]=='u')
          count[3]++;
        else if(s[i]=='r')
          count[4]++;
        else
        {
          cout<<"NO"<<endl;
          termino = true;
          break;
        }
      }
      if(!termino)
      {
        for(int i=0; i<count.size();i++)
        {
          if(count[i]!=1 && !termino)
          {
            cout<<"NO"<<endl;
            termino = true;
            break;
          }
        }
        
        if(!termino) 
          cout<<"YES"<<endl;
      }
    }  
  }
}