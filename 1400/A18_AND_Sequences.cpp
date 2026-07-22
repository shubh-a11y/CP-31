#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

long long fact(int n)
{
    long long res = 1;
    for(int i=2;i<=n;i++)
    {
        res = (res*i)%mod;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        long long totalAnd = a[0];
        for(int i=0;i<n;i++)
        {
            totalAnd = totalAnd &  a[i];
        }
        
        long long count = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == totalAnd)
            {
                count++;
            }
        }

        if(count < 2)
        {
            cout<<0<<endl;
        }
        else
        {
            long long ans = (count*(count-1))%mod;
            ans = ans*fact(n-2)%mod;
            cout<<ans<<endl;
        }
    }
}