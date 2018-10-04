vector<int> Solution::wave(vector<int> &A)
{
    std::sort (A.begin(), A.end());
    int n = A.size();
    int i=0,temp=0;
    for(i=0;i<n/2;i++)
    {
      temp=A[2*i+1];
      A[2*i+1]=A[2*i];
      A[2*i]=temp;
    }
    return A;

}
