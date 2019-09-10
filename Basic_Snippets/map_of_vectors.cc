#include <bits/stdc++.h>
using namespace std;

void display(map<int,vector<int> > M)
{
  for(auto i = M.begin(); i != M.end(); i++)
  {
    vector<int> V = i->second;
    for(auto j : V)
    cout<<j<<" ";
    cout<<endl;
  }
  cout<<endl;
}
int main()
{
  map <int , vector<int> > M;
  M[0].push_back(1);
  M[0].push_back(1);
  M[0].push_back(2);

  vector<int> V(10,-1);
  M.insert(make_pair(1,V));
  M[1].push_back(3);

  M.insert(make_pair(5,vector<int>()));
  M[5].push_back(9);
  display(M);
  return 0;
}
