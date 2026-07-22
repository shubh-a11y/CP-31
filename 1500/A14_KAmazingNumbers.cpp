
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

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        unordered_map<long long,long long> lastidx;
        map<long long,long long> maxDist;

        for(int i=0;i<n;i++)
        {
            if(lastidx.find(a[i]) != lastidx.end())
            {
                maxDist[a[i]] = max(maxDist[a[i]],i-lastidx[a[i]]);
                lastidx[a[i]] = i;
            }
            else
            {
                maxDist[a[i]] = i+1;
                lastidx[a[i]] = i;
            }
        }

        for(auto it:maxDist)
        {
            maxDist[it.first] = max(maxDist[it.first],n-lastidx[it.first]);
        }

        vector<long long> ans(n,LLONG_MAX);
        for(auto it: maxDist)
        {
            if(ans[it.second-1] == LLONG_MAX)
            {
                ans[it.second-1] = it.first; 
            }
        }
        
        for(int i=1;i<n;i++)
        {
            ans[i] = min(ans[i],ans[i-1]);
        }

        for(int i=0;i<n;i++)
        {
            if(ans[i] == LLONG_MAX)
            {
                cout<<-1<<" ";
            }
            else
            {
                cout<<ans[i]<<" ";
            }
        }
        cout<<endl;

    }
}