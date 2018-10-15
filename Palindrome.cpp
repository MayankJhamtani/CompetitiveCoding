int Solution::isPalindrome(int A)
{
    int n=0,d,i;
    int B=A;
    while(A!=0)
    {
        d=A%10;
        A=A/10;
        n=n*10+d;
    }
    if(n==B)
    {
        return 1;
    }
    return 0;
}
