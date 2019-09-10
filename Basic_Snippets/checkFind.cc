#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> S;
  S.push_back("A");
  S.push_back("B");

  S.push_back("C");

  S.push_back("D");

  S.push_back("E");

  cout<<*find(S.begin(),S.end(),"C")<<endl;
  cout<<find(S.begin(),S.end(),"C") - S.begin();
}
