#include <bits/stdc++.h>
using namespace std;

int main()
{
  multiset <int> M;
  M.insert(1);
  M.insert(1);
  M.insert(2);
  M.insert(2);
  M.insert(3);
  cout<<*advance(M.begin(),2);
  return 0;
}
