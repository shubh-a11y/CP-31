
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<long long> a(n);
        vector<long long> b(n);

        bool twos = false;
        unordered_map<long long,long long> mp;

        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];

            if(twos)
            {
                continue;
            }

            if(a[i] == b[i])
            {
                twos = true;
                continue;
            }

            mp[a[i]]++;
            mp[b[i]]++;

            if(mp[a[i]] > 2 || mp[b[i]] > 2)
            {
                twos = true;
            }
        }

        if(twos)
        {
            cout<<"NO"<<endl;
            continue;
        }


        vector<vector<long long>> adj(n+1);

        for(int i=0;i<n;i++)
        {
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }

        vector<bool> vis(n+1,false);
        queue<long long> q;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int count = 1;
                q.push(i);
                vis[i] = true;

                while(q.empty() == false)
                {
                    long long node = q.front();
                    q.pop();

                    for(auto it: adj[node])
                    {
                        if(!vis[it])
                        {
                            vis[it] = true;
                            q.push(it);
                            count++;
                        }
                    }
                }

                if(count%2 == 1)
                {
                    twos = true;
                    break;
                }
                
            }
        }


        if(twos)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}