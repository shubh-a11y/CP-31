
#include<bits/stdc++.h>
using namespace std;

long long GCDOF(long long a,long long b)
{
    if(b == 0)
    {
        return a;
    }
    return GCDOF(b, a % b);
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

        vector<long long> divisors;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i == 0)
            {
                divisors.push_back(i);

                if(i != (n/i))
                {
                    divisors.push_back(n/i);
                }
            } 
        }

        sort(divisors.begin(),divisors.end());

        int sz = divisors.size();

        int cn = 0;
        
        for(int i=0;i<sz;i++)
        {
            int k = divisors[i];
            long long gcd = 0;

            for(int j=0;j<=k-1;j++)
            {
                for(int l=j+k;l<n;l+=k)
                {
                    gcd = GCDOF(gcd,abs(a[l]-a[l-k]));
                }
            }

            if((gcd == 0) || (gcd > 1))
            {
                cn++;
            }
        }

        cout<<cn<<endl;

        
    }
}