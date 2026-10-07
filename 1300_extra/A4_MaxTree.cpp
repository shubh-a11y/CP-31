
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

        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);

        for(int i=1;i<n;i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;

            if(x>y)
            {
                adj[v].push_back(u);
                indegree[u]++;
            }
            else
            {
                adj[u].push_back(v);
                indegree[v]++;
            }
        }


        int idx = 1;

        queue<int> q;
        
        for(int i=1;i<=n;i++)
        {
            if(indegree[i] == 0)
            {
                // cout<<"Inserting node: "<<i<<endl;
                q.push(i);           
            }
        }

        vector<int> ans(n+1,0);
        while(q.empty() == false)
        {
            int sz = q.size();

            for(int i=0;i<sz;i++)
            {
                int tp = q.front();
                q.pop();
                
                ans[tp] = idx;
                idx++;
                
                for(auto it:adj[tp])
                {
                    indegree[it]--;
                    if(indegree[it] == 0)
                    {
                        // cout<<"Inserting node: "<<it<<endl;
                        q.push(it);
                    }
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}