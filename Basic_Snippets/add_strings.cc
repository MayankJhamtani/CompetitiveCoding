#include <bits/stdc++.h>
using namespace std;

string addStrings(string A, string B)
{
  if(A.size()<B.size())
  swap(A,B);    //This is a constant time operation, and only switches some internal pointers.

  //Reverse strings now, reverse answer before return.
  reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());

  string ans="";
  int carry=0;
  for(int i=0;i<B.size();i++)
  {
    int temp = (A[i]-'0') + (B[i] -'0') + carry;
    carry = temp/10;
    ans=to_string(temp%10)+ans;
  }
  cout<<ans<<" "<<carry<<endl;
  for(int i =B.size();i<A.size();i++)
  {
    int temp = (A[i]-'0') + carry;
    carry = temp/10;
    ans=to_string(temp%10)+ans;
  }
  if(carry!=0)
  ans=to_string(carry)+ans;
  //reverse(ans.begin(),ans.end());
  return ans;
}

int main()
{
  string A = "94845134684646169";
  string B = "98748451645";
  string sum  = addStrings(A,B);
  cout<<sum<<endl;
  return 0;
}
