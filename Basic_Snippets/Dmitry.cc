#include <bits/stdc++.h>
using namespace std;

void demo_copy_map()
{
  map<string,int> M;
  M["Here"] = 4;
  M.insert({"There",5});
  M.insert({"Everywhere",9});
  vector < pair <string , int > > V(M.begin(),M.end());
  for(int i=0;i<V.size();i++)
  {
    cout<<V[i].first<<" "<<V[i].second<<endl;
  }
  cout<<endl;
  return;
}

void demo_setUnion()
{

  vector<int> V1;
  V1.push_back(1);
  V1.push_back(2);
  V1.push_back(3);
  V1.push_back(5);
  sort(V1.begin(),V1.end());
  vector<int> V2;
  V2.push_back(7);
  V2.push_back(3);
  V2.push_back(9);
  V2.push_back(1);
  sort(V2.begin(),V2.end());
  vector<int> temp(V1.size()+V2.size());
  vector<int> ans(temp.begin(),set_union(V1.begin(),V1.end(),V2.begin(),V2.end(),temp.begin()));
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}
int main()
{
  demo_copy_map();
  demo_setUnion();
  return 0;
}
