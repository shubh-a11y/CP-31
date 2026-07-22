
#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long n,x;
        cin>>n>>x;

        vector<long long> a(n);
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }

        long long ans = 0;
        long long min_val = a[0];
        long long max_val = a[0];

        for(long long i=0;i<n;i++)
        {
            min_val = min(min_val,a[i]);
            max_val = max(max_val,a[i]);

            if(max_val-min_val > 2*x)
            {
                min_val = a[i];
                max_val = a[i];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}