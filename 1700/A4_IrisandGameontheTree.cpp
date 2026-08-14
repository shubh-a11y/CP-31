
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
        for(int i=0;i<n-1;i++)
        {
            long long u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string s;
        cin>>s;

        vector<int> leaves;

        for(int i=1;i<=n;i++)
        {
            if((adj[i].size() == 1) && i != 1)
            {
                leaves.push_back(i);
            }
        }

        int sz = leaves.size();
        int leaves0 = 0;
        int leaves1 = 0;
        int leaves_ = 0;
        int empty = 0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '?')
            {
                empty++;
            }
        }

        for(int i=0;i<sz;i++)
        {
            int idx = leaves[i];

            if(s[idx-1] == '0')
            {
                leaves0++;
            }
            else if(s[idx-1] == '1')
            {
                leaves1++;
            }
            else
            {
                leaves_++;
            }
        }


        if(s[0] == '0')
        {
            if(leaves_%2 == 0)
            {
                cout<<leaves1 + leaves_/2<<endl;
            }
            else
            {
                cout<<leaves1 + leaves_/2 + 1<<endl;
            }
        }
        else if(s[0] == '1')
        {
            if(leaves_%2 == 0)
            {
                cout<<leaves0 + leaves_/2<<endl;
            }
            else
            {
                cout<<leaves0 + leaves_/2 + 1<<endl;
            }
        }
        else
        {

            if(leaves0 != leaves1)
            {
                cout<<max(leaves0,leaves1) + leaves_/2<<endl;
            }
            else
            {
                if((empty-1-leaves_)%2 == 0)
                {
                    cout<<leaves0 + leaves_/2<<endl;
                }
                else
                {
                    if(leaves_%2 == 0)
                    {
                        cout<<leaves0 + leaves_/2<<endl;
                    }
                    else
                    {
                        cout<<leaves0 + leaves_/2 + 1<<endl;
                    }
                }
                
            }



        }

    }
}