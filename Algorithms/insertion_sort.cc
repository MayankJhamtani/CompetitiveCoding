#include <bits/stdc++.h>
using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

void display(vector<int>& A)
{
  for(int i=0;i<A.size();i++)
  cout<<A[i]<<" ";
  cout<<endl;
}
int main()
{
  int n = 8;
  vector<int> A(n,0);
  int temp;
  for(int i=0;i<n;i++)
  {
    cin>>temp;
    A[i]=temp;
  }
  display(A);
  //Insertion Sort, using for loop.
  int i,j;
  for(int i=1;i<A.size();i++)
  {
    temp = A[i];
    for(j=i-1;j>=0;j--)
    {
      if(A[j]>temp)
      A[j+1] = A[j];
      else break;
    }
    A[j+1] = temp;
    display(A);
  }
  //display
  display(A);
}
