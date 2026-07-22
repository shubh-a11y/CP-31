
#include <bits/stdc++.h>
using namespace std;

void DFS(long long node, long long color, vector<long long> &visited, vector<vector<long long>> &adj, long long &color0, long long &color1)
{
    visited[node] = 1;
    if(color == 0)
    {
        color0++;
    }
    else
    {
        color1++;
    }

    for(auto it: adj[node])
    {
        if(visited[it] == 0)
        {
            DFS(it,1-color,visited,adj,color0,color1);
        }
    }
}

int main()
{
    long long n;
    cin>>n;

    vector<vector<long long>> adj(n+1);

    for(int i=0;i<n-1;i++)
    {
        long long a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<long long> visited(n+1,0);

    // As we know, that in a bipartite graph, we can color the graph using two colors, and we can use BFS or DFS to color the graph.
    // We will use BFS to color the graph, and we will start from the first vertex

    long long color0 = 0;
    long long color1 = 0;

    DFS(1,0,visited,adj,color0,color1);

    cout<<color0*color1 - (n-1)<<endl;

}