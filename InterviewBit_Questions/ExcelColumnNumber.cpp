int Solution::titleToNumber(string A)
{
    int n=A.size();
    int i=0,d;
    int sum=0;
    char ch;
    for(i=0;i<n;i++)
    {
        ch=A[i];
        d=int(ch)-64;
        sum=sum*26+d;
    }
    return sum;
}
