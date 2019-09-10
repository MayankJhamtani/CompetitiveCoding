#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main()
{
  set <int> S;
  S.insert(5);
  S.insert(6);
  cout<<S.size();

  int val1 = 10;
  if(val1>S.size())
  cout<<val1;

  
  return 0;
}
