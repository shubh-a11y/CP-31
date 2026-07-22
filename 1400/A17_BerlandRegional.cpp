
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> u(n), s(n);
        for(int i=0;i<n;i++)
        {
            cin>>u[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }

        map<long long, vector<long long>> mp;
        for(int i=0;i<n;i++)
        {
            mp[u[i]].push_back(s[i]);
        }

        vector<long long> ans(n,0);

        for(auto &it: mp)
        {
            vector<long long> &vec = it.second;
            sort(vec.begin(),vec.end(),greater<long long>());
            
            int len = vec.size();
            vector<long long> prefix(len,0);
            prefix[0] = vec[0];
            for(int i=1;i<len;i++)
            {
                prefix[i] = prefix[i-1]+vec[i];
            }

            for(int k=0;k<len;k++)
            {
                int idx = k+1;
                ans[k] += prefix[len-1-(len%idx)];
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}