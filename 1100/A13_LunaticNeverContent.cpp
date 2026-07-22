
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
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
        int n;
        cin>>n;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        if(n == 1)
        {
            cout<<0<<endl;
            continue;
        }

        vector<long long> diffs;

        for(int i=0;i<n/2;i++)
        {
            diffs.push_back(abs(a[i] - a[n-1-i]));
        }

        int m = diffs.size();

        if(m == 1)
        {
            cout<<diffs[0]<<endl;
            continue;
        }

        long long ans = 0;

        for(int i=0;i<m;i++)
        {
            ans = gcd(ans,diffs[i]);
        }

        cout<<ans<<endl;
    }
}