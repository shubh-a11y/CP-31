
#include <bits/stdc++.h>
using namespace std;

void DFS(long long node, long long parent, long long lastIdx, vector<vector<pair<long long,long long>>> &adj, vector<long long> &dp)
{
    if(node == parent)
    {
        return;
    }

    for(auto &child: adj[node])
    {
        int childNode = child.first;
        int idx = child.second;
        if(childNode != parent)
        {
            if(idx < lastIdx)
            {
                dp[childNode] = dp[node] + 1; // If the index of the edge is less than the last index, we need to read the tree again
            }
            else
            {
                dp[childNode] = dp[node]; // Otherwise, we can continue reading the tree without reading it again
            }

            DFS(childNode,node,idx,adj,dp); // Recur for the child node
        }
    }
}
int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<vector<pair<long long,long long>>> adj(n+1);

        for(int i=0;i<n-1;i++)
        {
            long long u,v;
            cin>>u>>v;
            
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }

        vector<long long> dp(n+1,0); // Number of readings needed to reach each node

        dp[1] = 1;

        DFS(1,-1,-1,adj,dp); // current node, parent node, last index, adjacency list, dp array

        // dp[i] // The number of readings needed to reach node i

        long long maxReadings = 0;
        for(int i=1;i<=n;i++)
        {
            maxReadings = max(maxReadings, dp[i]);
        }
        cout<<maxReadings<<endl;
    }
}