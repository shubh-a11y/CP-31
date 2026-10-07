
#include <bits/stdc++.h>
using namespace std;

int res = 0;

pair<int,int> dfs(int node,int parent,vector<vector<long long>> &adj, string &s)
{
    int total = 1;
    int black;

    if(s[node-1] == 'B')
    {
        black = 1;
    }
    else
    {
        black = 0;
    }



    for(auto child: adj[node])
    {
        if(child == parent)
        {
            continue;
        }

        pair<int,int> it = dfs(child,node,adj,s);
        total += it.first;
        black += it.second;
    }

    if((black > 0) && (total - black) == black)
    {
        res++;
    }

    return {total, black};
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<long long> a(n+1);

        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
        }

        string s;
        cin>>s;

        vector<vector<long long>> adj(n+1);

        for(int i=2;i<=n;i++)
        {
            adj[a[i]].push_back(i);
        }
        res = 0;
        dfs(1,-1,adj,s);
        cout<<res<<endl;
    }
}