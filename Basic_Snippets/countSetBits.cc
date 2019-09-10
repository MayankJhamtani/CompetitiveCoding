//count set bits in ans and return.
#include <bits/stdc++.h>
using namespace std;
int countSetBits(int ans)
{
    int ctr=0;
    for(int i=0;i<32;i++)
    {
        //cout<< (1<<i) <<endl;
        if( (ans >> i) & 1 == 1)
        ctr++;
    }
    cout<<ctr<<endl;
    if(ctr%2==0)
    return 1;
    else return 0 ;

}
/*
unsigned int countSetBits(unsigned int n)
{
unsigned int count = 0;
while (n)
{
    count += n & 1;
    n >>= 1;
}
return count;
}*/
int main()
{
     int ans = countSetBits(1);
     ans = countSetBits(3);
     ans = countSetBits(5);
     ans = countSetBits(11);
     return 0;
}
