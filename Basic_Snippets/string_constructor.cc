#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s1 = "Hello World!";
  vector<char> V(s1.size(),' ');
  for(int i=0;i<s1.size();i++)
  {
    V[i] = s1[i];
  }

  string s2(V.begin(),V.end());
  cout<<s2<<endl;
  return 0;
}
