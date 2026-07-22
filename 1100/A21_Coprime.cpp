
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

        unordered_map<long long, long long> mp;
        for(int i=0;i<n;i++)
        {
            mp[a[i]] = i;
        }

        long long ans = 0;
        for(int i=1;i<=1000;i++)
        {
            if(mp.find(i) != mp.end())
            {
                for(int j=i;j<=1000;j++)
                {
                    if(mp.find(j) != mp.end())
                    {
                        if(__gcd(i,j) == 1)
                        {
                            ans = max(ans, mp[i] + mp[j]+2);
                        }
                    }
                }
            }
        }
        if(ans == 0)
        {
            ans = -1;
        }
        cout<<ans<<endl;
    }
}