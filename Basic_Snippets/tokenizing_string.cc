#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

vector<string> tokenize_natively(string str)
{
  //Assume delimeters are " " and ".", and rest everything is part of word.
  vector <string> V;
  string temp="";
  for(int i=0;i<str.size();i++)
  {
    if(str[i]==' ' || str[i]=='.')
    {
      V.push_back(temp);
      temp="";
    }
    else
    {
      temp=temp+str[i];
    }
  }
  return V;
}

void display(vector <string> V)
{
  for(int i=0;i<V.size();i++)
  {
    cout<<V[i]<<" ";
  }
  cout<<endl;
  return;
}
int main()
{
  char s[]="Hello World!. Lets get started. You ready?";

  //Method 1: Tokenize natively, without any functions.
  vector<string> V1 = tokenize_natively(s);
  display(V1);

  //Method 2: using strtok() inbuilt function.
  vector<string> V2;
  //char delimeters[2]={' ','.'};
  char* token = strtok(s," .");
  while(token!=NULL)
  {
    V2.push_back(token);
    token=strtok(NULL," .");
  }
  display(V2);

  return 0;
}
