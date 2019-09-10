int Solution::pow(int x, int n, int d)
{
    long long int xx=x;
    //x=3
    //n=5
    //d=4
    int prod=1;
    if(xx==0)
    {
        return 0;
    }
    else if(n==0)
    {
        return 1;
    }
    else
    {
        //x=x%d;
        while(n!=0)
        {
            if(n%2!=0)
            {
                prod=(prod*((xx+d)%d))%d;
                n--;
            }
            else
            {
                n=n/2;
                xx=((xx%d)*(xx%d))%d;
            }
        }
        return prod;
    }
}
