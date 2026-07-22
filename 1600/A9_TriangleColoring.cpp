
#include<bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long power(long long a,long long b)
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
    long long n;
    cin>>n;

    vector<long long> a(n);
    for(int i=0;i<n;i++)    {
        cin>>a[i];
    }

    long long ans = 1;

    for(int i=0;i<n;i+=3)
    {
        vector<long long> temp;
        temp.push_back(a[i]);
        temp.push_back(a[i+1]);
        temp.push_back(a[i+2]);

        sort(temp.begin(),temp.end());

        if((temp[0] == temp[1]) && (temp[1] == temp[2]))
        {
            ans = (ans*3) % mod;
        }
        else if(temp[0] == temp[1])
        {
            ans = (ans*2) % mod;
        }
        else
        {
            ans = (ans*1) % mod;
        }

    }

    long long n2 = n/3;

    for(int i=(n2/2)+1;i<=n2;i++)
    {
        ans = (ans*i) % mod;
    }

    for(int i=1;i<=(n2/2);i++)
    {
        ans = (ans*modInverse(i)) % mod;
    }

    cout<<ans<<endl;


}

