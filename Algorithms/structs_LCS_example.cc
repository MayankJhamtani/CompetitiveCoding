#include <bits/stdc++.h>
using namespace std;

struct LCS_Struct
{
  string s1;
  string s2;
  int lcs_len;
  string lcs;
  LCS_Struct(string str1, string str2)
  {
    s1=str1;
    s2=str2;
    lcs_len=0;
    lcs="";
  }
};
void findLCS(LCS_Struct* obj)
{
  string s1=obj->s1;
  string s2=obj->s2;
  obj->lcs_len=5;
  obj->lcs="aa";
  return;
}
void display(LCS_Struct* obj)
{
  cout<<obj->s1<<endl;
  cout<<obj->s2<<endl;
  cout<<obj->lcs_len<<":"<<obj->lcs<<endl;
}
int main()
{
  string s1="";
  string s2="";
  cin>>s1;
  cin>>s2;

  LCS_Struct* obj = new LCS_Struct(s1,s2);
  findLCS(obj);
  display(obj);

  LCS_Struct obj1(s1,s2);
  findLCS(&obj1);
  display(&obj1);
  return 0;
}
