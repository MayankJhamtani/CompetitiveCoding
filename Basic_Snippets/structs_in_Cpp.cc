#include <bits/stdc++.h>
using namespace std;
struct Val_Index
{
    int val1;
    int val2;
    int index1;
    int index2;

    Val_Index(int v1 ,int v2 , int i1 , int i2)
    {
        //The function signature above needs to be kept in mind.
        val1 = v1;
        val2 = v2;
        index1 = i1;
        index2 = i2;
    }

    //< returns true if this object is less than recieved object.
    bool operator < (Val_Index &V)
    {
      int temp1 = val1+val2;
      int temp2 = V.val1+V.val2;
      if(temp1<temp2)
      return true;
      else
      return false;
    }

    Val_Index operator + (Val_Index &V1)
    {
      Val_Index result(val1+V1.val1, val2+V1.val2, index1+V1.index1, index2+V1.index2);
      return result;
    }
};

void display( vector<Val_Index> V)
{
  for(int i=0;i<V.size();i++)
  {
    cout<<V[i].val1<<" "<<V[i].val2<<" "<<V[i].index1<<" "<<V[i].index2<<endl;
  }
  cout<<endl;
}

int main()
{
    vector <Val_Index> V;
    V.push_back(Val_Index(1,1,5,5));
    V.push_back(Val_Index(2,2,6,8));
    V.push_back(Val_Index(0,0,0,0));
    display(V);
    sort(V.begin(),V.end());
    display(V);

    Val_Index v1(1,1,5,5);
    Val_Index v2(2,2,10,10);
    Val_Index result  = v1+v2;
    cout<<result.val1;

}
