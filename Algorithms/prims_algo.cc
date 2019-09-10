typedef pair<int, int> pi;
int Solution::Prims(int A, vector<vector<int> > &B)
{
    int n = A; //number of vertices
    vector<bool> visited(n,false);

    //Note that to convert a priority_queue to min_heap
    //we need 2 additional arguments, the vector of the type same as priority_queue.
    priority_queue<pi, vector<pi>, greater<pi> > PQ;    //PQ in terms of (cost,destination).

    vector <pair<int,int> > adj[n]; //adjacency list in terms of (cost,destination)
    //convert to adjacency list.
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(make_pair(B[i][2],B[i][1]-1));
        adj[B[i][1]-1].push_back(make_pair(B[i][2],B[i][0]-1));
    }

    //Now do MST Prim's.
    //Pick up a node, insert it to PQ, then while PQ not empty,insert it's
    //neighbours into PQ, and proceed.
    //There are n nodes, 0 to n-1 . We added 0 to PQ to start.
    PQ.push(make_pair(0,B[0][0]-1)); //Reaching B[0][0] has cost 0. (We start from here)
    int total_cost=0;

    while(PQ.empty()!=true)
    {
        int node = PQ.top().second;
        if(visited[node]==true)
        {
            PQ.pop();
            continue;
        }
        else
        {
            total_cost+=PQ.top().first;
            PQ.pop();
            visited[node]=true;
            for(int i=0;i<adj[node].size();i++)
            {
                if(visited[adj[node][i].second]==false)
                {
                    PQ.push(make_pair(adj[node][i].first,adj[node][i].second));
                }
            }
        }
    }
    return total_cost;
}
