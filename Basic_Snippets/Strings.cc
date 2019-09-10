#include <iostream>
#include <string>
//#include <cstdio>
using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

int main ()
{
  //Various constructors. string s="Hello World" just overloads a constructor.
  std::string s0 ("Hello World!");
  std::string s1; //s1 is blank.
  std::string s2 (s0); //copy constructor.
  std::string s3 (s0, 2, 3); //start at 8th position of s0 and take 3 characters, or if s0 ends first then till there.
  std::string s4 ("A character sequence");
  std::string s6a (10, 'x');
  std::string s6b (10, 42);      // 42 is the ASCII code for '*'
  std::string s7 (s0.end()-1, s0.end());

  std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  std::cout << "\ns4: " << s4  << "\ns6a: " << s6a;
  std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';

  string sub=s0.substr(5);
  cout<<sub<<"*"<<endl;
  string::iterator i = s0.begin()+4;
  cout<<*i<<endl;
  cout<<i-s0.begin()<<endl;

  //Use of find.
  string str="Hello World! It's time to begin phase two.";
  size_t j = str.find("!");
  cout<<j<<endl;
  j=str.find("time");
  cout<<j<<endl;
  j=str.find("t");
  cout<<j<<endl;
  j=str.find("t",j+1);
  cout<<j<<endl;
  //Use of


}
