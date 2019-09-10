#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> V;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    V.push_back(temp);
  }

  ternarySearch(V);
}
