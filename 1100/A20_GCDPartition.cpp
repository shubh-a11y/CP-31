
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b,a%b);
}

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

        vector<long long> prefix(n);
        prefix[0] = a[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + a[i];
        }

        long long ans = 0;
        for(int i=0;i<n-1;i++)
        {
            ans = max(ans,gcd(prefix[i],prefix[n-1]-prefix[i]));
        }

        cout<<ans<<endl;


    }
}