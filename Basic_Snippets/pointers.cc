#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int a = 5;
  int *p = &a;
  int **pp = &p;
  //p is address of a.
  //*p is value of a.
  //*pp is address of a.
  //**pp is value of a.


  cout<<"Value of a, accessed by a: "<< a <<endl;
  cout<<"Address of variable a, accessed by &a: "<< &a <<endl;
  cout<<"Address of variable a, accessed by p: "<< p <<endl;
  cout<<"Value of a, accessed by *p: "<< *p <<endl;
  cout<<"Address of p, accessed by &p: "<< &p <<endl;
  cout<<"Address of p, accessed by pp: "<< pp <<endl;
  cout<<"Value at pp, accessed by *pp: "<< *pp <<endl;
  cout<<"Value at pp, accessed by **pp: "<< **pp <<endl;

}
