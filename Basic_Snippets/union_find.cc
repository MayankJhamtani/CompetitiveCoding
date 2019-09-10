#include <bits/stdc++.h>
using namespace std;

void init_DSU(vector<int>& V,int size)
{
  for(int i=0;i<size;i++)
  V.push_back(i);
}

void unionDSU(vector<int>& V, int x, int y)
{
  if(x>y)
  swap(x,y);
  int component1 = V[x];
  int component2 = V[y];
  for(int i=0;i<V.size();i++)
  {
    if(V[i]==component2)
    V[i] = component1;
  }
}

bool findDSU(vector<int>& V,int x,int y)
{
  if(V[x]==V[y])
  {
    return true;
  }
  return false;
}
void display(vector<int>& V)
{
  for(auto i : V)
  cout<<i<<" ";
  cout<<endl;
}
int main()
{
  vector<int> V;
  int size = 10;
  init_DSU(V,size);

  unionDSU(V,2,1);
  unionDSU(V,4,3);
  unionDSU(V,8,4);
  unionDSU(V,9,3);
  display(V);

  unionDSU(V,6,5);
  display(V);

  return 0;
}
