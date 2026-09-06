
#include<bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<long long> parent,size;
    int components;

    DSU(long long n)
    {
        components = n;
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=1;i<=n;i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(long long node)
    {
        if(parent[node] == node)
        {
            return node;
        }

        parent[node] = findParent(parent[node]);
        return parent[node];
    }

    void Union(long long u,long long v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if(uParent == vParent)
        {
            return;
        }

        if(size[uParent] < size[vParent])
        {
            size[vParent] += size[uParent];
            parent[uParent] = vParent;
            components--;
        }
        else
        {
            size[uParent] += size[vParent];
            parent[vParent] = uParent;
            components--;
        }
        
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m1,m2;
        cin>>n>>m1>>m2;

        vector<pair<long long,long long>> edgesF;
        vector<pair<long long,long long>> edgesG;


        for(int i=0;i<m1;i++)
        {
            long long u,v;
            cin>>u>>v;

            edgesF.push_back({u,v});
        }

        for(int i=0;i<m2;i++)
        {
            long long u,v;
            cin>>u>>v;

            edgesG.push_back({u,v});
        }

        DSU G(n);

        for(int i=0;i<m2;i++)
        {
            long long u = edgesG[i].first;
            long long v = edgesG[i].second;

            G.Union(u,v);

        }

        DSU F(n);

        long long ans = 0;

        for(int i=0;i<m1;i++)
        {
            long long u = edgesF[i].first;
            long long v = edgesF[i].second;


            if(G.findParent(u) != G.findParent(v))
            {
                ans++;
                continue;
            }
            else{
                F.Union(u,v);

            }
        }

        ans += F.components - G.components;

        cout<<ans<<endl;







        
    }
}
