
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<long long>> &adj,vector<long long> &sz,long long curr,long long par)
{
    sz[curr] = 1;

    for(auto x: adj[curr])
    {
        if(x != par)
        {
            DFS(adj,sz,x,curr);
            sz[curr] += sz[x];
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
        long long x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    if(n%2 != 0)
    {
        cout<<-1<<endl;
    }
    else
    {
        vector<long long> sz(n+1,0);

        long long curr = 1;
        long long par = -1;
        DFS(adj,sz,curr,par);

        int count = 0;
        for(int i=2;i<=n;i++)
        {
            if(sz[i]%2 == 0)
            {
                count++;
            }
        }

        cout<<count<<endl;

    }

}