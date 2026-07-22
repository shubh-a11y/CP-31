
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;

    vector<vector<long long>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n+1, false);

    vector<long long> ans;
    priority_queue<long long,vector<long long>, greater<long long>> pq;
    pq.push(1);
    visited[1] = true;

    while(!pq.empty())
    {
        int tp = pq.top();
        pq.pop();

        ans.push_back(tp);

        for(auto x:adj[tp])
        {
            if(!visited[x])
            {
                visited[x] = true;
                pq.push(x);
            }
        }
    }

    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<'\n';


}