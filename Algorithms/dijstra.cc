using namespace std;
#include <bits/stdc++.h>
int findNode(vector<int> &distance, vector<bool> &visited)
{
  int index=0;
  int min_dist=INT_MAX;
  for(int i=1;i<visited.size();i++)
  {
    if(visited[i]==true)
    continue;
    else if(min_dist>distance[i])
    {
      index=i;
      min_dist=distance[i];
    }
  }
  return index;
}

vector<int> restore_path(int s, int t, vector<int> const& p)
{
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    cout<<"printing from restore_path"<<endl;
    for(int i=0;i<path.size();i++)
    {
      cout<<path[i]<<" ";
    }
    cout<<endl;
    return path;

}

void shortestReach(int n, vector<vector<int>> edges, int s)
{
    int vertices = n+1;
    //Create adjacency list in form of <destination , distance >
    vector <pair <int, int> > adj[vertices];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        adj[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
    }

    //Create d[v] and p[v] and visited[];
    vector<int> d(vertices,INT_MAX);
    vector<bool> visited(vertices, false);
    vector<int> p(vertices,-1);

    //Initialization. Mark s distance as zero.
    d[s]=0;

    for(int i=0;i<vertices;i++)
    {
      //find the unvisited node with minimum distance.
      int present_node  = findNode(d,visited);
      visited[present_node]=true;
      for(int j=0; j<adj[present_node].size();j++)
      {
        if(d[adj[present_node][j].first] > d[present_node]+adj[present_node][j].second )
        {
          d[adj[present_node][j].first] = d[present_node]+adj[present_node][j].second;
          p[adj[present_node][j].first] = present_node;
        }
      }
    }
    cout<<"Cost to each node:"<<endl;
    for(int i=1;i<d.size();i++)
    {
      cout<<d[i]<<endl;
    }


    cout<<"Path to each node:"<<endl;
    for(int i=0;i<p.size();i++)
    {
      if(p[i]==-1)
      continue;
      restore_path(s,i,p);
    }
}


int main()
{
  int n=4;
  int s=1;
  vector <vector <int> > graph;

  vector<int> temp(3,0);

  temp[0]=1;
  temp[1]=2;
  temp[2]=2;
  graph.push_back(temp);

  temp[0]=1;
  temp[1]=3;
  temp[2]=4;
  graph.push_back(temp);

  temp[0]=2;
  temp[1]=3;
  temp[2]=3;
  graph.push_back(temp);

  temp[0]=4;
  temp[1]=1;
  temp[2]=1;
  graph.push_back(temp);

  temp[0]=4;
  temp[1]=2;
  temp[2]=1;
  graph.push_back(temp);

  temp[0]=4;
  temp[1]=3;
  temp[2]=1;
  graph.push_back(temp);

  shortestReach(n,graph,s);
  return 0;
}
