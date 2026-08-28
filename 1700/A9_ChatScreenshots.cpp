

#include<bits/stdc++.h>
using namespace std;


bool cycle(int i,vector<vector<int>> &adj,vector<bool> &inRecursion,vector<bool> &visited)
{
    inRecursion[i] = true;
    visited[i] = true;

    for(auto it:adj[i])
    {
        if(visited[it] == false)
        {
            if(cycle(it,adj,inRecursion,visited))
            {
                return true;
            }
        }
        else if(inRecursion[it] == true)
        {
            return true;
        }
    }

    inRecursion[i] = false;
    return false;
} 



int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        

        vector<vector<int>> adj(n+1);

        vector<vector<int>> a(k,vector<int>(n));
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }

        if(n <= 2)
        {
            cout<<"YES"<<endl;
            continue;
        }

        for(int i=0;i<k;i++)
        {
            for(int j=2;j<n;j++)
            {
                adj[a[i][j-1]].push_back(a[i][j]);
            }
        }


        vector<bool> visited(n+1,false);
        vector<bool> inRecursion(n+1,false);

        bool flag = false;
        
        for(int i=1;i<=n;i++)
        {

            if(!visited[i])
            {
                if(cycle(i,adj,inRecursion,visited))
                {
                    flag = true;
                    break;
                }
            }

        }

        if(flag)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }


    }
}