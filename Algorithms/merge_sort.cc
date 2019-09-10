#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}

vector<int> merge(vector<int> left, vector<int> right)
{
  vector<int> result(left.size()+right.size(),0);
  int ctr=0;
  int left_ctr = 0;
  int right_ctr = 0;
  while(left_ctr<left.size() && right_ctr<right.size())
  {
    if(left[left_ctr]<right[right_ctr])
    {
      result[ctr] = left[left_ctr];
      ctr++;
      left_ctr++;
    }
    else
    {
      result[ctr] = right[right_ctr];
      ctr++;
      right_ctr++;
    }
  }
    while(left_ctr<left.size())
    {
      result[ctr] = left[left_ctr];
      ctr++;
      left_ctr++;
    }
    while(right_ctr<right.size())
    {
      result[ctr] = right[right_ctr];
      ctr++;
      right_ctr++;
    }
    return result;
}

vector<int> mergeSort(vector<int> m)
{
   if (m.size() <= 1)
      return m;

   vector<int>result;
   int middle = ((int)m.size()+ 1) / 2;

   vector<int> left(m.begin(),m.begin()+middle);
   vector<int> right(m.begin()+middle,m.end());

   left = mergeSort(left);
   right = mergeSort(right);
   result = merge(left, right);

   return result;
}

int main()
{
   vector<int> v;

   v.push_back(38);
   v.push_back(27);
   v.push_back(43);
   v.push_back(3);
   v.push_back(9);
   v.push_back(82);
   v.push_back(10);

   print(v);
   cout << "------------------" << endl;

   v = mergeSort(v);
   print(v);
}
