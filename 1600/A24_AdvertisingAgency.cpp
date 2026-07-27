
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b)
{
    long long res = 1;

    while(b > 0)
    {
        if(b&1)
        {
            res = (res*a) % mod;
        }

        a = (a*a) % mod;
        b >>= 1;
    }

    return res;
}

long long modInverse(long long a)
{
    return power(a, mod-2);
}

int main()
{
    int t;
    cin>>t;

    vector<long long> fact(1001,1);
    vector<long long> invfact(1001,1);

    for(int i=2;i<=1000;i++)
    {
        fact[i] = (fact[i-1]*i) % mod;
    }

    invfact[1000] = modInverse(fact[1000]);


    for(int i=999;i>=2;i--)
    {
        invfact[i] = (invfact[i+1]*(i+1)) % mod;
    }

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<long long> a(n);
        unordered_map<long long,long long> mp1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mp1[a[i]]++;
        }
        
        sort(a.begin(),a.end());
        
        unordered_map<long long,long long> mp2;
        int count = 0;
        int idx = n-1;
        while(count < k)
        {
            mp2[a[idx]]++;
            idx--;
            count++;
        }

        long long ans = 1;

        for(auto it: mp2)
        {
            int total = mp1[it.first];
            int req = it.second;

            ans = (ans * (((fact[total] * invfact[req]) % mod) * invfact[total-req])%mod)%mod;
        }

        cout<<ans<<endl;


    }


}