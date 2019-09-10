#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void timeStringConcatenation()
{
  //Add strings by using + operator on characters.
  string x(1000,'0');
  string y1="";
  string y2="";
  string y3="";
  string y4="";

  //Run 1
  auto start1 = high_resolution_clock::now();
  for(int i=0;i<x.size();i++)
  {
    y1=y1+x[i];
  }
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
  cout<<" Time for copying by character from array: "<< duration1.count() << " microseconds" << endl;

  //Run 2
  auto start2 = high_resolution_clock::now();
  for(int i=0;i<x.size();i++)
  {
    y1=y1+'0';
  }
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2 - start2);
  cout<<" Time for copying by character directly: "<< duration2.count() << " microseconds" << endl;

  //Run 3
  auto start3 = high_resolution_clock::now();
  for(int i=0;i<x.size();i++)
  {
    y1.push_back(x[i]);
  }
  auto stop3 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(stop3 - start3);
  cout<<" Time for copying by character from array using push_back: "<< duration3.count() << " microseconds" << endl;

  //Run 4
  auto start4 = high_resolution_clock::now();
  for(int i=0;i<x.size();i++)
  {
    y1.push_back('0');
  }
  auto stop4 = high_resolution_clock::now();
  auto duration4 = duration_cast<microseconds>(stop4 - start4);
  cout<<" Time for copying by character directly: "<< duration4.count() << " microseconds" << endl;

}

void timeStringSwap()
{
  cout<<"Swapping Timed:"<<endl;
  string x(10000,'0');
  string y(10000,'1');

  //Run 1
  auto start1 = high_resolution_clock::now();
  string temp = x;
  x=y;
  y=temp;
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
  cout<<" Swapping naively "<< duration1.count() << " microseconds" << endl;

  //Run 2
  auto start2 = high_resolution_clock::now();
  swap(x,y);
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2 - start2);
  cout<<" Swapping using swap() "<< duration2.count() << " microseconds" << endl;
}

int main()
{
  timeStringConcatenation();
  timeStringSwap();
  return 0;
}
