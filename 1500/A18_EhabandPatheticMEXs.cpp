
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;

    vector<vector<vector<long long>>> adj(n+1);
    for(int i=0;i<n-1;i++)
    {
        long long x,y;
        cin>>x>>y;
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }

    vector<int> res(n-1,-1);

    int k = 0;

    for(int i=1;i<=n;i++)
    {
        if(adj[i].size() >= 3)
        {
            for(int j=0;j<=2;j++)
            {
                res[adj[i][j][1]] = k;
                k++;
            }
            break;
        }
    }

    for(int i=0;i<n-1;i++)
    {
        if(res[i] == -1)
        {
            res[i] = k;
            k++;
        }
    }

    for(int i=0;i<n-1;i++)
    {
        cout<<res[i]<<endl;
    }
    cout<<endl;

}