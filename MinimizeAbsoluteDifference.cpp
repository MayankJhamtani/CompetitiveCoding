int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int a=A.size();
    int b=B.size();
    int c=C.size();
    int ilow=0,jlow=0,klow=0,ihigh=a-1,jhigh=b-1,khigh=c-1;
    int min1,max1;
    int diff,g_diff=INT_MAX;
    bool flag=true;
    int ctr=0;
    while(flag==true)
    {
        max1=max(max(A[ihigh],B[jhigh]),C[khigh]);
        min1=min(min(A[ihigh],B[jhigh]),C[khigh]);
        diff=max1-min1;
        if(g_diff>diff)
        {
            //cout<<g_diff<<" ";
            g_diff=diff;
            if(g_diff==0)
            {
                break;
            }
        }
        if(max1==A[ihigh])
        {
            ihigh--;
            if(ihigh==-1)
            break;
        }
        else if(max1==B[jhigh])
        {
            jhigh--;
            if(jhigh==-1)
            break;
        }
        else if(max1==C[khigh])
        {
            khigh--;
            if(khigh==-1)
            break;
        }
    }
    return g_diff;
}
