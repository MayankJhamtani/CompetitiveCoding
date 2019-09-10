#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

int main()
{
  unordered_multimap <char,int> M;
  M.insert({'A',1});
  M.insert({'B',2});
  M.insert(make_pair('A',2));
  M.insert(make_pair('A',1));

  //Iterate over elements of unordered_multimap, and then use equal range.
  for(auto it = M.begin(); it!=M.end(); it++)
  {
    cout<<"Key: "<<it->first<<endl;
    auto iter_pair = M.equal_range(it->first);
    for(auto j = iter_pair.first; j!=iter_pair.second; j++)
    {
      cout<<j->first<<j->second<<endl;
    }
    cout<<"End of key"<<endl;
  }

  //Iterate over unique keys using upper_bound.
  for( auto it = M.begin(), end = M.end(); it != end; it = M.upper_bound('A') )
  {
    cout<<"Key: "<<it->first<<endl;
    auto iter_pair = M.equal_range(it->first);
    for(auto j = iter_pair.first; j!=iter_pair.second; j++)
    {
      cout<<j->first<<j->second<<endl;
    }
    cout<<"End of key"<<endl;
  }
  return 0;
}
