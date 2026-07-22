
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        vector<long long> a(n);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            long long val = a[i];
            int bit = 0;
            while(val>0)
            {
                if(val&1 == 1)
                {
                    mp[bit]++;
                }
                val = val>>1;
                bit++;
            }
        }

        long long ans = 0;
        for(int i=30;i>=0;i--)
        {
            if(n-mp[i] <= k)
            {
                ans += (1LL << i);
                k = k-(n-mp[i]);
            }
        }
        cout<<ans<<endl;

    }
}