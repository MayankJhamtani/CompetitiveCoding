#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void display(vector < vector <int> > &V)
{
  for(int i=0;i<V.size();i++)
  {
    for(int j=0;j<V[0].size();j++)
    {
      cout<<V[i][j]<<" ";
    }
    cout<<endl;
  }
}

void clear(vector<vector<int> > &V)
{
  for(int i=0;i<V.size();i++)
  {
    for(int j=0;j<V[0].size();j++)
    {
      V[i][j]=0;
    }
  }
}

void row_first(vector<vector<int> > &V)
{
  int ctr=0;
  for(int i=0;i<V.size();i++)
  {
    for(int j=0;j<V[0].size();j++)
    {
      V[i][j]=ctr++;
    }
  }
}

void column_first(vector<vector<int> > &V)
{
  int ctr=0;
  for(int j=0;j<V[0].size();j++)
  {
    for(int i=0;i<V.size();i++)
    {
      V[i][j]=ctr++;
    }
  }
}

void principal_diagonal_first(vector<vector<int> > &V)
{
  int ctr=0;
  for(int offset=0;offset<V.size();offset++)
  {
    for(int start=0;start<V.size()-offset;start++)
    {
      V[start][start+offset]=ctr++;
    }
  }
}

void first_cell_first(vector<vector<int> > &V)
{
  int ctr=0;
  for(int sum=0;sum<V.size();sum++)
  {
    for(int i=0;i<=sum;i++)
    {
      V[sum-i][i]=ctr++;
    }
  }
}
int main()
{
  int m=5;
  int n=5;
  //create a vector with m rows and n columns, and initialize to 0's.
  vector<vector<int> > vect(m,vector<int>(n,0));
  display(vect);

  row_first(vect);
  display(vect);
  clear(vect);
  cout<<endl;

  column_first(vect);
  display(vect);
  clear(vect);
  cout<<endl;

  principal_diagonal_first(vect);
  display(vect);
  clear(vect);
  cout<<endl;

  first_cell_first(vect);
  display(vect);
  clear(vect);
  cout<<endl;

  return 0;
}
