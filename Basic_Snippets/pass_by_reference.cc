#include <bits/stdc++.h>
using namespace std;

void display1(int a)
{
  cout<<a<<endl;
}

void display2(int* a)
{
  cout<<a<<endl;
}

void display3(int& a)
{
  cout<<a<<endl;
}
int main()
{
  int a = 5;
  display1(a);
  display2(*a);
  display3(&a);
}
