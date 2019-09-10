#include <bits/stdc++.h>
using namespace std; //(If we use this, then we don't need to use std::<> everywhere.)

void string_constructors()
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
}

void string_iterators(string s)
{
  string sub=s.substr(5);
  cout<<sub<<endl;
  string::iterator i = s.begin()+4;
  cout<<*i<<endl;
  cout<<i-s.begin()<<endl;
}

void find_functions(string s)
{
  //Use of find.
  size_t j = s.find("3");
  if(j!=string::npos)
  cout<<s[j]<<endl;

  j=s.find("345");
  if(j!=string::npos)
  cout<<j<<endl;

  j = s.find_first_of("zxy1234");
  if(j!=string::npos)
  cout<<j<<" "<<s[j]<<endl;

  j = s.find_first_not_of("01234");
  if(j!=string::npos)
  cout<<j<<" "<<s[j]<<endl;

  //Similarly there are find_last_of(), find_last_not_of();
}

void string_modifying_functions(string s)
{
  //Erase : 3 versions.
  string s1(s.begin(),s.end());
  s1.erase(s1.begin()+5);       //Erase a character pointed by iterator.
  cout<<s1<<endl;

  s1=s;
  s1.erase(s1.begin()+3,s1.begin()+5);    //Erase characters in the range.
  cout<<s1<<endl;

  s1=s;
  s1.erase(3,5);      //Erase start at index 3 and span 5. Note that this does not accept iterators.
  cout<<s1<<endl;

  //insert : too complex to remember.
  //replace : too complex. :(

  //erase all spaces.
  string test = " 1111 222   33  4   ";
  auto end_pos = std::remove(test.begin(), test.end(), ' ');
  test.erase(end_pos, test.end());
  cout<<test<<endl;
}

int main ()
{
  string easy = "0123456789abcdefghijkl";
  //string_constructors();
  //string_iterators(easy);
  //find_functions(easy);
  string_modifying_functions(easy);

}
