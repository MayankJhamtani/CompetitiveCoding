vector<int> Solution::plusOne(vector<int> &A)
{
    int n=A.size();
    int ctr=0,i=0,index=0;
    bool flag=false;
    while(A[0]==0)
    {
        for(i=0;i<n-1;i++)
        {
            A[i]=A[i+1];
        }
        A.pop_back();
        n--;
        if(n==0)
        {
            break;
        }
    }
    if(A.empty()==true)
    {
        A.push_back(1);
        //cout<<A[0];
        return A;
    }
    for(i=0;i<n;i++)
    {
        if(A[i]!=9)
        {
            break;
        }
        if(i==(n-1))
        {
            flag=true;
        }
    }

    if(flag==true)
    {
        A.push_back(0);
        n=A.size();
        A[0]=1;
        for(i=1;i<n;i++)
        {
            A[i]=0;
        }
        return A;
    }
    for(i=n-1;i>=0;i--)
    {
        if(A[i]!=9)
        {
            A[i]=A[i]+1;
            break;
        }
        if(A[i]==9)
        {
            A[i]=0;
            //cout<<A[i];
        }
    }
    return A;
}
