#include <bits/stdc++.h>
using namespace std;

/*
All sorting techniques are to be implemented here.
Take a vector input, and return the sorted vector.
BubbleSort
SelectionSort
InsertionSort
QuickSort
MergeSort
BucketSort
CountingSort
Test File format :
    a number n, the size of array.
    n numbers follow.
    Numbers need not be integers.
*/
void display(vector<int> &V)
{
  int n=V.size();
  for(auto i : V)
  {
    cout<<i<<" ";
  }
  cout<<endl;
}

vector<int> BubbleSort(vector<int> V)
{
  bool no_swaps = false;
  for(int i=0;i<V.size()-1;i++)
  {
    if(no_swaps==true)
    break;
    no_swaps=true;
    for(int j=0;j<V.size()-1-i;j++)
    {
      if(V[j]>V[j+1])
      {
        swap(V[j],V[j+1]);
        no_swaps==false;
      }
    }
  }
  return V;
}

vector<int> SelectionSort(vector<int> V)
{
  //Select the minimum element and put it at the beginning to sort ascending.
  int min_index=0;
  for(int i=0;i<V.size()-1;i++)
  {
    min_index=i;
    for(int j=i+1;j<V.size();j++)
    {
      if(V[j]<V[min_index])
      {
        min_index=j;
      }
    }
    swap(V[i],V[min_index]);
  }
  return V;
}

vector<int> InsertionSort(vector<int> V)
{
  //Subtle difference as compared to Selection sort.
  //Idea : At i = i_0, take the i_th element and put it at the correct place.
  //
  int element=0;
  int j;
  for(int i=1;i<V.size();i++)
  {
    element=V[i];
    j=i;
    while(V[j-1]>element && j>=1)
    {
      V[j]=V[j-1];
      j--;
    }
    V[j]=element;
  }
  return V;
}

int main()
{
  int n;
  cin>>n;
  vector<int> V(n,0);
  //Accept vector.
  for(int i=0;i<n;i++){
    cin>>V[i];
  }
  display(V);

  /*
  vector<int> V_bubble = BubbleSort(V);
  display(V_bubble);
  */

  /*
  vector<int> V_selection = SelectionSort(V);
  display(V_selection);
  */

  vector<int> V_insertion = InsertionSort(V);
  display(V_insertion);
}
