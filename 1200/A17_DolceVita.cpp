
#include<bits/stdc++.h>
using namespace std;

long long biSearch(long long val, int idx,long long x )
{
    long long low = 0;
    long long high = 1e9+5;

    long long days = 0;
    while(low <= high)
    {
        long long mid = low + (high - low)/2;
        if(val + mid*(idx+1) <= x) // mid => days
        {
            days = mid+1;
            low = mid+1;
        } 
        else{
            high = mid-1;
        }
    }

    return days;


}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,x;
        cin>>n>>x;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a.begin(),a.end());
        vector<long long> prefix(n);
        prefix[0] = a[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = prefix[i-1] + a[i];
        }

        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += biSearch(prefix[i],i,x);
        }
        cout<<ans<<endl;

    }
}