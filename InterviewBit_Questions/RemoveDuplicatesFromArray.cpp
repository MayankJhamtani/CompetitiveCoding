int Solution::removeDuplicates(vector<int> &A)
{
    int n=A.size();
    int i;
    if (n==0 || n==1)
        return n;
    int j = 0;
    // Doing same as done in Method
    for (int i=0; i < n-1; i++)
    {
        if (A[i] != A[i+1])
        {
            A[j++] = A[i];
        }
    }
    A[j++] = A[n-1];
    int temp=j;
    return temp;
}
