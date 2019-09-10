#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int getWays(int numFaces,int numDice,int target, unordered_map <string ,long long int >& M)
{
    if(target<=0)
    return 0;
    cout<<"numFaces: "<<numFaces<<" numDice:"<<numDice<<" Target: "<<target<<endl;
    if(numDice<=0)
    {
      return 0;
    }
    else if(numDice==1)
    {
        if(target<=numFaces)
        {
          cout<<"Returning 1"<<endl;
          return 1;
        }
        else
        {
          cout<<"Returning 0"<<endl;
          return 0;
        }
    }
    string s = to_string(numDice)+" "+to_string(target);
    if(M.find(s)!=M.end())
    {
      cout<<"Returning: "<<M[s]<<endl;
      return M[s];
    }

    long long int ans=0;
    for(int i=1;i<=numFaces;i++)
    {
        ans = ans + getWays(numFaces,numDice-1,target-i,M);
    }

    M.insert({s,ans});
    cout<<"Returning:"<<ans<<endl;
    return ans;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
    	int numDice,numFaces,target_sum;
    	cin>>numFaces;
    	cin>>numDice;
    	cin>>target_sum;
    	unordered_map <string ,long long int > M;     //M in terma of (numDice, target) : numberOfWays.
    	long long int ans = getWays(numFaces,numDice,target_sum,M);
    	cout<<ans<<endl;
	}
	return 0;
}
