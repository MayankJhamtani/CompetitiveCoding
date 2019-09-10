#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &V)
{
  for(auto i : V)
  cout<<i<<" ";
  cout<<endl;
}
int partition(vector<int>& V,int left,int right)
{
  //At end of partition function, all elements left of pivot will be smaller than pivot, and all elements towards right will be larger.
  int partition_index=left;
  int pivot_element = V[right];
  for(int i=left;i<=right;i++)
  {
    if(V[i]<pivot_element)
    {
      swap(V[i],V[partition_index]);
      partition_index++;
    }
  }
  swap(V[right],V[partition_index]);
  return partition_index;
}
void quickSort(vector<int>& V, int left, int right)
{
  if(left>=right)
  return;
  int partition_index = partition(V,left,right);
  quickSort(V,left,partition_index-1);
  quickSort(V,partition_index+1,right);
}
int main()
{
  int n = 1000;
  vector<int> v(n,0);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }

  print(v);
  cout << "------------------" << endl;
  quickSort(v,0,v.size()-1);
  print(v);
}
