


#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>  Ipair;

vector<int> djikstra(vector <pair<int,int> > adj[],int source,int numNodes)
{
    vector<bool> visited(numNodes,false);
    priority_queue <Ipair, vector<Ipair> , greater<Ipair> > PQ;
    vector<int> distance(numNodes,INT_MAX);
    distance[source] = 0;
    PQ.push({0,source});
    while(PQ.empty()==false)
    {
        cout<<"*"<<endl;
        auto pair = PQ.top();
        PQ.pop();
        int src = pair.second;
        int cost = pair.first;
        cout<<"src: "<<src<<" cost: "<<cost<<endl;
        if(visited[src]==true)
        continue;
        visited[src] = true;
        for(int i=0;i<adj[src].size();i++)
        {
            cout<<"**"<<endl;
            auto pair_temp = adj[src][i];
            int cost2 = pair_temp.first;
            int dst = pair_temp.second;
            cout<<"dst: "<<dst<<" cost2: "<<cost2<<endl;
            if(cost2+distance[src]<distance[dst])
            {
                cout<<"***"<<endl;
                distance[dst] = cost2+distance[src];
                PQ.push({distance[dst],dst});
            }
        }
    }
    return distance;
}
void display(vector <pair<int,int> > adj[], int numNodes)
{
  for(int i=0;i<numNodes;i++)
  {
    for(int j = 0; j<adj[i].size(); j++)
    {
      cout<<adj[i][j].first<<":"<<adj[i][j].second<<" ";
    }
    cout<<endl;
  }
}
int main()
{
    int nodes,edges;
    cin>>nodes;
    cin>>edges;
    vector <pair <int,int> > adj[nodes+1];     //Cost,Destination. One extra node.
    for(int i=0;i<edges;i++)
    {
        int src,dst,cost;
        cin>>src>>dst>>cost;
        adj[src-1].push_back({cost,dst-1});
        adj[dst-1].push_back({cost,src-1});
    }
    int booze_cities;
    cin>>booze_cities;
    for(int i=0;i<booze_cities;i++)
    {
        int city;
        cin>>city;
        adj[nodes].push_back({0,city-1});
        adj[city-1].push_back({0,nodes});
    }
    display(adj,nodes+1);
    //Now do djikstra with source as nodes.
    //Create a function that returns a vector of minimum distances using djikstra.
    int source = nodes;
     vector <int> ans = djikstra(adj,source,nodes+1);
    for(int i=0;i<ans.size()-1;i++)
    {
      cout<<ans[i]<<endl;
    }
    return 0;
}
