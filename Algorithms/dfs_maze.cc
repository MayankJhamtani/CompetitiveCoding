#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char> >& matrix,int x,int y, vector<vector<bool> > visited, int& ans)
{
  //cout<<"*"<<endl;
  if(matrix[x][y]=='*')
  {
    return;
  }
  //cout<<"**"<<endl;
  visited[x][y] = true;
  //cout<<"***"<<endl;
  int arr1[] = {1,0,-1,0};
  int arr2[] = {0,1,0,-1};
  for(int i=0;i<4;i++)
  {
    //cout<<x<<" "<<y<<endl;
    int new_x = x+arr1[i];
    int new_y = y+arr2[i];
    if(matrix[new_x][new_y]=='*' && visited[new_x][new_y]==false)
    ans++;
    else if(visited[new_x][new_y]==false && matrix[new_x][new_y]=='.')
    {
      dfs(matrix,new_x,new_y,visited,ans);
    }
  }
}
void display(vector<vector<char> >& matrix)
{
  for(int i=0;i<matrix.size();i++)
  {
    for(int j=0;j<matrix[0].size();j++)
    {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
int main()
{
  int M,N,K;
  cin>>M;
  cin>>N;
  cin>>K;
  vector<vector<char> > matrix(M,vector<char>(N,' '));
  char ch;
  for(int i=0;i<M;i++)
  {
    for(int j=0;j<N;j++)
    {
      cin>>ch;
      matrix[i][j] = ch;
    }
  }
  //display(matrix);
  //take k inputs.
  vector<vector<bool> > visited(M,vector<bool>(N,false));
  int x,y;
  int ans=0;
  for(int i=0;i<K;i++)
  {
    //cout<<"*"<<endl;
    cin>>x>>y;
    dfs(matrix,x-1,y-1,visited,ans);
    cout<<ans<<endl;
    ans=0;
  }
  return 0;
}
