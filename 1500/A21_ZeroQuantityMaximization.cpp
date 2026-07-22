
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;

    vector<long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<long long> b(n);
    for(long long i=0;i<n;i++)
    {
        cin>>b[i];
    }

    map<pair<long long,long long>, long long> mp;
    long long alwaysZero = 0;
    long long maxFreq = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
        {
            if(b[i] == 0)
            {
                alwaysZero++;
            }
            continue;
        }

        long long gcd = __gcd(abs(a[i]), abs(b[i]));
        long long num = -b[i]/gcd;
        long long den = a[i]/gcd;

        if(den < 0)
        {
            den = -den;
            num = -num;
        }

        mp[{num,den}]++;
        maxFreq = max(maxFreq, mp[{num,den}]);
    } 

    cout<<maxFreq + alwaysZero<<endl;
}