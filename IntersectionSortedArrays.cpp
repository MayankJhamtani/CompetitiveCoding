vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{
    int n=A.size();
    int m=B.size();
    int i,j,temp;
    vector <int> vect;
    int j_t=0;
    for(i=0;i<n;i++)
    {
        for(j=j_t;j<m;j++)
        {
            if(A[i]==B[j])
            {
                j_t=j+1;
                vect.push_back(A[i]);
                break;
            }
            else if(A[i]<B[j])
            {
                break;
            }
        }
    }
    return vect;
}
