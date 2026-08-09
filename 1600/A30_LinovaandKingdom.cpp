
#include <bits/stdc++.h>
using namespace std;


void FillDepth(vector<vector<int>>& adj, vector<int>& depth, int curr)
{

    for(auto child: adj[curr])
    {
        if(depth[child] == -1)
        {
            depth[child] = depth[curr]+1;
            FillDepth(adj,depth,child);
        }
    }
}

void FillSize(vector<vector<int>>& adj, vector<int>& size, int curr, int parent)
{
    int currsize = 1;

    for(auto child: adj[curr])
    {
        if(child == parent)
        {
            continue;
        }

        FillSize(adj,size,child,curr);
        currsize += size[child];

    }

    size[curr] = currsize;

}

int main()
{
    long long n;
    long long k;
    cin>>n>>k;
    
    vector<vector<int>> adj(n+1);

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> depth(n+1, -1);

    vector<int> size(n+1, -1);

    depth[1] = 0;

    int curr = 1;

    FillDepth(adj,depth,curr);

    int parent = -1;

    FillSize(adj,size,curr,parent);

    vector<int> score(n+1);
    score[0] = INT_MAX;
    
    for(int i=1;i<=n;i++)
    {
        score[i] = depth[i]-size[i]+1;
    }


    sort(score.begin(),score.end(),greater<int>());

    long long res = 0;
    for(int i=1;i<=k;i++)
    {
        res += score[i];
    }

    cout<<res<<endl;

}