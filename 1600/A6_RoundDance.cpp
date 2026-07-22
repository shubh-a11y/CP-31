#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        vector<vector<ll>> a(n+1);

        set<pair<ll, ll>> s;

        for(ll i=1;i<=n;i++)
        {
            ll x;
            cin>>x;

            if(i < x)
            {
                s.insert({i,x});
            }
            else if(i > x)
            {
                s.insert({x,i});
            }
        }

        for(auto it : s)
        {
            a[it.first].push_back(it.second);
            a[it.second].push_back(it.first);
        }

        ll components = 0;
        ll cycles = 0;

        vector<bool> visited(n+1, false);

        for(ll i=1;i<=n;i++)
        {
            if(visited[i] == false)
            {
                vector<bool> inComponent(n+1, false);
                vector<ll> parent(n+1, -1);
                components++;
                queue<ll> q;
                q.push(i);
                visited[i] = true;
                inComponent[i] = true;
                bool hasCycle = false;

                while(q.empty() == false)
                {
                    ll curr = q.front();
                    q.pop();

                    for(auto it:a[curr])
                    {
                        if(visited[it] == false)
                        {
                            visited[it] = true;
                            inComponent[it] = true;
                            q.push(it);
                            parent[it] = curr;
                        }
                        else if(it != parent[curr] && inComponent[it] == true)
                        {
                            hasCycle = true;
                        }

                    }
                }

                if(hasCycle)
                {
                    cycles++;
                }

            }
        }

        cout<<cycles+min(1LL,components-cycles)<<" "<<components<<endl;
    }
}