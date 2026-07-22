#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<pair<long long,long long>> edges;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            if(u>v) swap(u,v);
            edges.push_back({u,v});
        }
        
        vector<int> closest_bad(n+1, n+1);
        for(int i=0;i<m;i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            closest_bad[u] = min(closest_bad[u],v);
        }

        long long ans = 0;

        int min_right = n+1;
        for(int i=n;i>=1;i--)
        {
            min_right = min(min_right,closest_bad[i]);
            {
                ans += min_right-i;
            }
        }

        cout<<ans<<endl;
        
        
    }
}