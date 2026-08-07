
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k,z;
        cin>>n>>k>>z;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> prefix(n);
        prefix[0] = a[0];

        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1]+a[i];
        }

        long long rem = k;

        long long res = a[0];
        long long maxpair = a[0]+a[1];

        for(int i=1;i<=k;i++)
        {
            rem--;
            long long curr = prefix[i];
            maxpair = max(maxpair,a[i]+a[i-1]);

            if((((rem+1)/2) > z))
            {
                res = max(res,curr);
                continue;
            }

            if(rem%2 == 0)
            {
                curr += (rem/2)*maxpair;
            }
            else
            {
                curr += (rem/2)*maxpair + a[i-1];
            }

            res = max(res,curr);
            
        }

        cout<<res<<endl;
    }

}