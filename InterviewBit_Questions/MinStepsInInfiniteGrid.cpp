int Solution::coverPoints(vector<int> &A, vector<int> &B)
{
    int s=A.size();
    int i,ctr,dist;
    int px,py,qx,qy;
    for(i=0;i<s-1;i++)
    {
        px=A[i];
        py=B[i];
        qx=A[i+1];
        qy=B[i+1];
        px=px-qx;
        py=py-qy;
        if(px<0)
        {
            px=px*(-1);
        }
        if(py<0)
        {
            py=py*(-1);
        }
        dist=max(px,py);
        ctr=ctr+dist;
    }
    return ctr;
}
