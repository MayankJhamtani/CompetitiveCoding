#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void display(priority_queue <int, vector<int> >& PQ)
{
  while(PQ.empty()!=true)
  {
    cout<<PQ.top()<<" ";
    PQ.pop();
  }
  cout<<endl<<"*********************************"<<endl;
  return;
}
int main()
{
  //Add to PQ one by one, and all at once.
  vector<int> V(1000,0);
  int temp;
  for(int i=0;i<1000;i++)
  {
    cin>>temp;
    V[i] = temp;
  }
  //Run 1
  auto start1 = high_resolution_clock::now();
  priority_queue <int, vector<int> > PQ1(V.begin(),V.end());
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
  cout<<" Time for inserting all at once: "<< duration1.count() << " microseconds" << endl;


  //Run 2
  auto start2 = high_resolution_clock::now();
  priority_queue <int, vector<int> > PQ2;
  for(int i=0;i<1000;i++)
  {
    PQ2.push(V[i]);
  }
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2 - start2);
  cout<<" Time for inserting one by one: "<< duration2.count() << " microseconds" << endl;

  //Display both PQ's.
  display(PQ1);
  display(PQ2);

}
