/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Ipair;

void djikstra(int numNodes, vector<pair<int,int> > adj[], int source, vector<int>& distance)
{
    cout<<"*"<<endl;
    vector<bool> visited(numNodes,false);
    distance[source]=0;
    priority_queue <Ipair , vector<Ipair> , greater<Ipair> > PQ;
    //push source to PQ with distance zero.
    PQ.push({0,source});
    while(PQ.empty()==false)
    {
        //get top of PQ.
        auto pair = PQ.top();
        PQ.pop();
        int src = pair.second;
        //int cost = pair.first;
        if(visited[src]==true)
        continue;
        else
        {
            visited[src]=true;
            //iterate over neighbours of src.
            for(auto u : adj[src])
            {
                int cost2 = u.first;
                int dst = u.second;
                if(distance[dst] > distance[src]+cost2)
                {
                    distance[dst] = distance[src]+cost2;
                    PQ.push({distance[dst],dst});
                }
            }
        }
    }

}
int main()
{
    int nodes,edges,pfee;
    cin>>nodes>>edges>>pfee;
    vector<pair<int,int> > adj[nodes];   //directed edges.
    vector<int> capacity(nodes,0);
    for(int i=0;i<nodes;i++)
    {
        cin>>capacity[i];
    }
    for(int i=0;i<edges;i++)
    {
        int src,dst,cst;
        cin>>src>>dst>>cst;
        adj[src-1].push_back({cst,dst-1});
    }
    int numCars;
    cin>>numCars;

    vector<int> distances(nodes,INT_MAX);
    djikstra(nodes,adj,0,distances);
    for(auto i : distances)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}
