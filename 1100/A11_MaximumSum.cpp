
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        sort(a.begin(),a.end());

        vector<long long> prefix_sum(n);
        prefix_sum[0] = a[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + a[i];
        }

        long long start = 0;
        long long end = n-1;
        long long ans = prefix_sum[end-k];

        for(int i=1;i<=k;i++)
        {
            start = 2*i;
            end = n-1-(k-i);
            
            ans = max(ans, prefix_sum[end] - (start > 0 ? prefix_sum[start-1] : 0));
        }

        cout<<ans<<endl;
    }
}