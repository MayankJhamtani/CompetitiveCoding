#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int main()
{
  set <vector <int > > S;
  vector <int> temp(5,0);
  S.insert(temp);
  for(auto it = S.begin(); it!=S.end(); it++)
  {
    //cout<<*it[0];   //causes error.
    cout<<(*it)[0]; //displays 0th element of the vector.
  }
}
