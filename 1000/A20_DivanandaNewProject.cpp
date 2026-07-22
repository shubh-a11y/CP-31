
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
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<vector<long long>> v; // storing number of visits and their indexes

        for(long long i=0;i<n;i++)
        {
            v.push_back({a[i],i+1});
        }

        sort(v.begin(),v.end(),greater<vector<long long>>()); // sort in decreasing order of visits

        vector<long long> ans(n+1);

        ans[0] = 0;
        long long walk = 0;

        int curr = 0;
        int idx = 0;
        while(idx < n)
        {
            curr++;
            walk += 2*(curr)*(v[idx][0]);
            ans[v[idx][1]] = curr;
            idx++;

            if(idx < n)
            {
                walk += 2*(curr)*(v[idx][0]);
                ans[v[idx][1]] = -curr;
                idx++;
            }


        }

        cout<<walk<<endl;
        for(int i=0;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }


}