#include <bits/stdc++.h>
using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

int main()
{
  string s1="quetzalcoatl";
  string s2="tezcatlipoca";

  vector<vector<int> > dp(s1.size(),vector<int>(s2.size(),0));

  //Fill first row.
  int temp=0;
  for(int i=0;i<s2.size();i++)
  {
    if(s2[i]==s1[0])
    temp=1;
    dp[0][i]=temp;
  }
  //fill first column.
  temp=0;
  for(int i=0;i<s1.size();i++)
  {
    if(s1[i]==s2[0])
    temp=1;
    dp[i][0]=temp;
  }


  for(int i=1;i<s1.size();i++)
  {
    for(int j=1;j<s2.size();j++)
    {
      if(s1[i]==s2[j])
      dp[i][j]=dp[i-1][j-1]+1;
      else dp[i][j] = max(dp[i-1][j], max(dp[i][j-1],dp[i-1][j-1]));
    }
  }

  //display dp;
  for(int i=0;i<dp.size();i++)
  {
    for(int j=0;j<dp[0].size();j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }


  //backtracking doesn't work for now. :(
  //Printing the LCS using backtracking.
  int m = s1.size();
  int n = s2.size();
  int lcs_len = dp[m-1][n-1];
  cout<<lcs_len<<" *1"<<endl;
  char lcs[lcs_len+1];
  lcs[lcs_len] = '\0'; // Set the terminating character
  int i = m-1 , j = n-1;
  cout<<"loop started"<<endl;
  while (i > 0 && j > 0)
  {
    cout<<i<<" : "<<j<<endl;
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (s1[i] == s2[j])
      {
          cout<<s1[i]<<" ";
          lcs[lcs_len-1] = s1[i]; // Put current character in result
          i--; j--; lcs_len--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (dp[i-1][j] > dp[i][j-1])
         i--;
      else
         j--;
   }

   // Print the lcs
   cout << "LCS of " << s1 << " and " << s2 << " is " << lcs;

  return 0;
}
