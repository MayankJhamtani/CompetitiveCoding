int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(),A.end());
    int n=A.size();
    int i;
    int min=INT_MAX,temp;
    for(i=0;i<n-1;i++)
    {
        temp=A[i]^A[i+1];
        if(temp<min)
        {
            min=temp;
        }
    }
    return min;
}
