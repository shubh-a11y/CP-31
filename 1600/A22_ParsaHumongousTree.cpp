
#include <bits/stdc++.h>
using namespace std;

void DFS(long long node, long long parent, vector<vector<long long>>& adj, vector<vector<long long>>& dp,vector<pair<long long,long long>>& v)
{
    for(auto child: adj[node])
    {
        if(child == parent)
        {
            continue;
        }

        DFS(child,node,adj,dp,v);

        dp[node][0] += max(dp[child][0] + abs(v[node-1].first - v[child-1].first), dp[child][1] + abs(v[node-1].first - v[child-1].second));
        dp[node][1] += max(dp[child][0] + abs(v[node-1].second - v[child-1].first), dp[child][1] + abs(v[node-1].second - v[child-1].second));
    }
}

int main()
{
    // 1. FAST I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<pair<long long,long long>> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
        }

        vector<vector<long long>> adj(n+1);

        for(int i=0;i<n-1;i++)
        {
            long long u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<long long>> dp(n+1,vector<long long>(2,0));

        DFS(1,-1,adj,dp,v); // current node, parent node, adjacency list, dp table

        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
}