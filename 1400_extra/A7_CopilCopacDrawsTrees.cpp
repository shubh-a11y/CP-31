
#include <bits/stdc++.h>
using namespace std;


void DFS(int node,int parent,int prev_idx,vector<vector<pair<int,int>>> &adj,vector<int> &dp)
{
    if(node == parent)
    {
        return;
    }
    
    for(auto x:adj[node])
    {
        int child = x.first;
        int idx = x.second;
        
        if(child == parent)
        {
            continue;
        }
        
        if(prev_idx > idx)
        {
            dp[child] = dp[node]+1;
        }
        else
        {
            dp[child] = dp[node];
        }
        
        DFS(child,node,idx,adj,dp);
    }
}

int main() 
{
    
    int t;
    cin>>t;
        
    while(t--)
    {
        long long n;
        cin>>n;
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            
            adj[x].push_back({y,i});
            adj[y].push_back({x,i});
            
            
        }
        
        vector<int> dp(n+1,-1);
        // dp[i] = rounds taken to cover ith node;
        dp[1] = 1;
        
        DFS(1,-1,-1,adj,dp);
        
        
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            ans = max(ans,dp[i]);
        }
        
        cout<<ans<<endl;
        
    }
}