int BinarySearch(const vector<int> &A, int B,bool flag)
{
    int high=A.size()-1;
    int low=0;
    int mid;
    int result=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]==B)
        {
         result=mid;
         if(flag==true)
         {
            high=mid-1;
         }
         else
         {
             low=mid+1;
         }
        }
        else if(A[mid]>B)
        {
            high=mid-1;
        }
        else if(A[mid]<B)
        {
            low=mid+1;
        }
    }
    return result;
}

vector<int> Solution::searchRange(const vector<int> &A, int B)
{
    vector <int> vect;
    int start=BinarySearch(A,B,true);
    if(start==-1)
    {
        vect.push_back(-1);
        vect.push_back(-1);
        return vect;
    }

    int end=BinarySearch(A,B,false);
    vect.push_back(start);
    vect.push_back(end);
    return vect;
}
