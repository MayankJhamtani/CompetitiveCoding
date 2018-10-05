void Solution::setZeroes(vector<vector<int> > &A)
{
    int k=0;
   int r=0;
   for(int i=0;i<A.size();i++){
       if(A[i][0]==0){
           k=1;
           break;
       }
   }
   for(int j=0;j<A[0].size();j++){
       if(A[0][j]==0){
           r=1;
           break;
       }
   }

   for(int i=1;i<A.size();i++){
       for(int j=1;j<A[0].size();j++){
           if(A[i][j]==0)
           {
               A[i][0]=0;
               break;
           }
       }
   }
   for(int j=1;j<A[0].size();j++){
       for(int i=1;i<A.size();i++){
           if(A[i][j]==0){
               A[0][j]=0;
               break;
           }
       }
   }
