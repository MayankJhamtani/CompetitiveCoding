#include <bits/stdc++.h>
using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

void checkCall(char* arr)
{
  string s;
  while(*arr != '\0')     //If we check against null, then we get a warning, but it works.
  {
    s=s+*arr;
    arr++;
  }
  cout<<s<<endl;
  return;
}

int main()
{
  //NOTE: with the below lines, we run into "cannot convert string to char* arr"
  // string s = "Hello World !";
  // checkCall(s);

  char arr[10] = {'h','e','l','l','o','w','o','r','l','d'};
  checkCall(arr);
  return 0;
}
