int Solution::sqrt(int A)
{
    double low=0;
    double high=A;
    double mid;
    int ctr=0;
    while(low<=high && ctr<100)
    {
        ctr++;
        mid=(low+high)/2;
        if(mid*mid==A)
        {
            return int(floor(mid));
        }
        else if((mid*mid)>A)
        {
            high=mid;
           // cout<<"high "<<high<<endl;
        }
        else if((mid*mid)<A)
        {
            low=mid;
           // cout<<"low "<<low<<endl;
        }
    }
    return int(floor(mid));

}
