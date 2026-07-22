
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, h;
    cin>>n>>h;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long long ans = 0;

    long long l = 0;
    long long r = n-1;

    while(l <= r)
    {
        long long mid = l + (r-l)/2;
        long long sum = 0;
        vector<long long> dummy = a;
        sort(dummy.begin(), dummy.begin()+mid+1,greater<long long>());

        for(int i=0;i<=mid;i+=2)
        {
            sum += dummy[i];
        }

        if(sum <= h)
        {
            ans = mid+1;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    cout<<ans<<endl;
}