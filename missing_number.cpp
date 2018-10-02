vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    long long int n = A.size();
    long long int sum=0;
    long long int sum_squared=0;
    long long int i;
    long long int S=0,SS=0;
    for(i=0;i<n;i++)
    {
        sum=sum+(long long)(A[i]);
        sum_squared+=(long long)(A[i])*(long long) (A[i]);
    }
    S=(long long)(n*(n+1)/2);
    SS=(long long)(n*(n+1)*(2*n+1)/6);
    //cout<<S<<SS<<sum<<sum_squared<<endl;
    long long int diff = sum-S;
    long long int diff_sq = sum_squared-SS;
    long long int sum_num = diff_sq/diff;
    int x =int((sum_num+diff)/2);
    int y =int((sum_num-diff)/2);
    vector <int> C{x,y};
    return C;
}
