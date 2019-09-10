

#include <bits/stdc++.h>
using namespace std;

void allPermutations(vector<char> V,int index, int& ans)
{
  if(index==V.size())
  return;
  

}

int main()
{
  string s;
  cin>>s;
  int ans = 0;
  vector<char> V;
  for(int i=0;i<s.size();i++)
  V.push_back(s[i]);

  int n = V.size();
  int index = -1;
  int ans=0;
  allPermutations(V,index,ans);

}
