#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool compare(int a,int b)
{
  if(a%2==0 && b%2==0)
  return false;
  else if(a%2==0)
  return true;
  return false;
}

int main()
{
  vector <int> V;
  //Fill up the simple vector.
  for(int i=0;i<10;i++)
  {
    V.push_back(i);
  }
  sort(V.begin(),V.end(),compare);

  //display vector
  for(int i=0;i<10;i++)
  {
    cout<<V[i]<<" ";
  }
  return 0;
}
