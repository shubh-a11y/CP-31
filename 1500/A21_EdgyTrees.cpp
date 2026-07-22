
#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long power(long long a,long long b)
{
    long long res = 1;

    while(b > 0)
    {
        if(b&1)
        {
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }

    return res;
}


int main()
{
    long long n,k;
    cin>>n>>k;

    vector<vector<long long>> adj(n+1);

    for(int i=0;i<n-1;i++)
    {
        long long u,v,x;
        cin>>u>>v>>x;

        if(x == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> comps;
    vector<int> visited(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(visited[i] == -1)
        {
            int count = 1;
            queue<int> q;
            q.push(i);

            while(!q.empty())
            {
                int tp = q.front();
                q.pop();
                visited[tp] = 1;

                for(auto x: adj[tp])
                {
                    if(visited[x] == -1)
                    {
                        visited[x] = 1;
                        count++;
                        q.push(x);
                    }
                }
            }
            comps.push_back(count);
        }
    }

    long long res = power(n,k);

    for(int i=0;i<comps.size();i++)
    {
        res = (res - power(comps[i],k) + mod)%mod;
    }

    cout<<res<<endl;


}