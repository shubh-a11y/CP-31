
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
        vector<long long> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        unordered_map<long long,long long> mp; // For storing how many elements of
        // a are gretaer than a given element of b
        for(int i=0;i<n;i++)
        {
            int idx = upper_bound(a.begin(),a.end(),b[i]) - a.begin();
            mp[b[i]] = n - idx;
        }

        long long ans = 1;
        const long long mod = 1e9 + 7;
        for(long long i=n-1;i>=0;i--)
        {
            ans = (ans * max(1LL*0,mp[b[i]]-(n-i-1))) % mod;
        }

        cout<<ans<<endl;

    }

}