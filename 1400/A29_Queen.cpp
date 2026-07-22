
#include <bits/stdc++.h>
using namespace std;


// void DFS(int node, vector<long long>& good, vector<vector<long long>>& adj, vector<long long>& visited, bool& flag)
// {
//     visited[node] = 1;

//     if(good[node] == 1)
//     {
//         flag = false;
//         return;
//     }
//     else{
//         for(auto it: adj[node])
//         {
//             if(visited[it] == 0)
//             {
//                 DFS(it,good,adj,visited,flag);
//             }
//         }
//     }
// }


int main()
{
    long long n;
    cin>>n;

    vector<vector<long long>> p_c;
    vector<vector<long long>> adj(n);
    vector<long long> good(n,0);
    for(int i=0;i<n;i++)
    {
        long long p,c;
        cin>>p>>c;

        if(c == 0)
        {
            good[i] = 1;
        }

        if(p == -1)
        {
            continue;
        }

        adj[p-1].push_back(i);

        p_c.push_back({p,c});
    }

    vector<long long> res;
    for(int i=0;i<n;i++)
    {
        if(good[i] == 0)
        {
            // vector<long long> visited(n,0);
            // DFS(i,good,adj,visited,flag);
            bool flag = true;
            for(auto it: adj[i])
            {
                if(good[it] == 1)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                res.push_back(i+1);
            }

        }
    }

    if(res.size() == 0)
    {
        cout<<-1<<endl;
        return 0;
    }

    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    
    
    

    



}