#include <bits/stdc++.h>
using namespace std;


unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while (n)
    {
        count += n & 1;
        n >>= 1;
    }
  //cout<<"Set Bits: "<<count<<endl;
  return count;
}
bool checkXOREven(vector<int>& V, int l, int r)
{
    //cout<<"Printing Window"<<endl;
    int ans = 0;
    for(int i=l;i<r;i++)
    {
        ans = ans ^ V[i];
    }
    //cout<<"XOR'd bits: "<<ans<<endl;
    ans = countSetBits(ans);
    if(ans%2==0)
    return true;
    else return false;
}
void display(vector<int>& V)
{
  for(auto i : V)
  cout<<i<<" ";
  cout<<endl;
}
int getMaxLength(vector<int>& V)
{
  //display(V);
  //Assume the longest window size.
  int num_window = 1;
  for(int window_size = V.size();window_size>=0;window_size--)
  {
    for(int start_index = 0; start_index<num_window; start_index++)
    {
      if(checkXOREven(V,start_index,start_index+window_size))
      return window_size;
    }
    num_window++;
  }
}
int main()
{
    vector<int> ans;
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,k;
        cin>>n>>k;
        vector<int> V(n,0);
        for(int j=0;j<n;j++)
        {
          cin>>V[j];
        }
        for(int j=0;j<k;j++)
        {
          int index;
          int new_value;
          cin>>index>>new_value;
          V[index] = new_value;
          int max_length = getMaxLength(V);
          ans.push_back(max_length);
        }
        cout<<"Case #"<<i+1<<":";
        for(auto j : ans)
        cout<<" "<<j;
        cout<<endl;
        ans.clear();
    }
}
