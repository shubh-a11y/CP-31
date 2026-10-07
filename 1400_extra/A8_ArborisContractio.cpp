#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;



        vector<vector<long long>> adj(n+1);

        for(int i=1;i<n;i++)
        {
            long long u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if(n == 2)
        {
            cout<<0<<endl;
            continue;
        }
        
        int leafTotal = 0;
        vector<int> leaf(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size() == 1)
            {
                leafTotal++;
                leaf[i] = 1;
            }
        }

        int maxAdjLeaf = 0;
        for(int i=1;i<=n;i++)
        {
            int count = 0;
            for(auto it:adj[i])
            {
                if(leaf[it] == 1)
                {
                    count++;
                }
            }

            maxAdjLeaf = max(maxAdjLeaf,count);


        }



        cout<<leafTotal - maxAdjLeaf<<endl;        


    }
}