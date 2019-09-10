#include <bits/stdc++.h>
using namespace std;

int getAns(int eggs, int floors, unordered_map<string,int>& M)
    {
        if(floors==1 || floors==0)
        {
          //cout<<"Returning 1"<<endl;
          return floors;
        }
        //cout<<eggs<<" "<<floors<<endl;
        if(eggs==1)
        {
            //cout<<"Returning Floors: "<<floors<<endl;
            return floors;
        }
        string s = to_string(eggs)+" "+to_string(floors);
        if(M.find(s)!=M.end())
        {
            cout<<"Returning via map: " <<M[s]<<endl;
            return M[s];
        }
        int ans=INT_MAX;
        for(int i=1;i<=floors;i++)
        {
            ans = min(ans , max( getAns(eggs,floors-i,M) , getAns(eggs-1,i-1,M) ));
        }
        ans=ans+1;
        M.insert({s,ans});
        //cout<<"Returning ans: "<<ans<<endl;
        return ans;
    }
int superEggDrop(int K, int N)
{
    unordered_map <string,int> M;
    return getAns(K,N,M);
}

int main()
{
  cout<<superEggDrop(4,2000);
  return 0;
}
