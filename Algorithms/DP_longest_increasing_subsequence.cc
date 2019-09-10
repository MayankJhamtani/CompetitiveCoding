#include <bits/stdc++.h>
using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

void findLIS(vector<int>& V)
{
  vector<int> dp(V.size(),1);
  vector<int> parent(V.size(),-1);  //-1 shows no existing parent.
  for(int i=1;i<V.size();i++)
  {
    for(int j=i;j>=0;j--)
    {
      if(V[j]<V[i] && dp[i]<(dp[j]+1))
      {
        dp[i]=dp[j]+1;
        parent[i]=j;
      }
    }
  }
  //First find last element of LIS, which may not be the last element
  //of dp[]. Then use parent to get LIS.
  auto max_elem = max_element(dp.begin(),dp.end());
  int max_index = max_elem-dp.begin();
  cout<<"LIS length is: "<<*max_elem <<" equaivalent to "<<dp[max_index]<<endl;
  vector<int> LIS;
  for(int i = max_index; i!=-1; i = parent[i])
  LIS.push_back(V[i]);
  reverse(LIS.begin(),LIS.end());
  for(auto i : LIS)
  cout<<i<<" ";
  cout<<endl;
  return;
}

int main()
{
  vector<int> V = {10,22,9,33,21,50,41,60,80};
  findLIS(V);
}
