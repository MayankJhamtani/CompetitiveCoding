using namespace std;
#include <bits/stdc++.h>
int main()
{
    unordered_multimap <int,int> M;
    M.insert(make_pair(2,3));
    M.insert(make_pair(2,4));
    auto pair_iter = M.equal_range(2);
    for(auto it = pair_iter.first; it!=pair_iter.second; it++)
    {
      cout<<it->second<<" ";
    }
    cout<<endl;
}
