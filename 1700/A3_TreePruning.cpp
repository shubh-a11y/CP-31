
#include <bits/stdc++.h>
using namespace std;

long long DFS(long long node,vector<vector<long long>> & adj,vector<long long> &nodesAtLevel,vector<long long> &nodesMaxDepth,long long depth, vector<bool> &visited)
{
    visited[node] = true;
    nodesAtLevel[depth]++;

    long long maxDepth = depth;

    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            maxDepth = max(maxDepth,DFS(it,adj,nodesAtLevel,nodesMaxDepth,depth+1,visited));
        }
    }

    nodesMaxDepth[maxDepth]++;
    return maxDepth;
    




}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<vector<long long>> adj(n+1);
        for(int i=0;i<n-1;i++)
        {
            long long u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<long long> nodesAtLevel(n+2,0);
        vector<long long> nodesMaxDepth(n+1,0);

        vector<bool> visited(n+1,false);

        long long d = DFS(1,adj,nodesAtLevel,nodesMaxDepth,1,visited);

        for(int i=1;i<=n;i++)
        {
            nodesMaxDepth[i] += nodesMaxDepth[i-1];
        }

        for(int i=n-1;i>=0;i--)
        {
            nodesAtLevel[i] += nodesAtLevel[i+1];
        }

        long long res = INT_MAX;
        
        for(int i=1;i<=d;i++)
        {
            long long temp = nodesMaxDepth[i-1] + nodesAtLevel[i+1];
            res = min(res,temp);
        }

        cout<<res<<endl;

    }
}