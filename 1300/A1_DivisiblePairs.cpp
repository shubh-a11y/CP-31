
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,x,y;
        cin>>n>>x>>y;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<pair<long long,long long>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({a[i]%x,a[i]%y});
        }

        map<pair<long long,long long>,long long> mp;
        for(int i=0;i<n;i++)
        {
            mp[v[i]]++;
        }

        long long ans = 0;
        for(auto it:mp)
        {
            long long x1 = it.first.first;
            long long y1 = it.first.second;

            if(mp[{x1,y1}]==0)
            {
                continue;
            }

            long long x2,y2;

            if(x1==0)
            {
                x2 = 0;
            }
            else{
                x2 = (x-x1)%x;
            }
            y2 = y1;

            if(mp.find({x2,y2})!=mp.end())
            {
                if(x1 == x2 && y1 == y2)
                {
                    ans += (it.second*(it.second-1))/2;
                }
                else
                {
                    ans += it.second*mp[{x2,y2}];
                }
            }

            mp[{x1,y1}] = 0;
             mp[{x2,y2}] = 0;

        }

        cout<<ans<<endl;


    }
}