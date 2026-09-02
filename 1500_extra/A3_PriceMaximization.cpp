
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<pair<long long,long long>> v;

        for(int i=0;i<n;i++)
        {
            v.push_back({a[i]%k,i});
        }

        sort(v.begin(),v.end());

        long long ans = 0;

        int l = 0;
        int r = n-1;

        while(l<r)
        {
            long long sum1 = v[l].first + v[r].first;

            if(sum1 >= k)
            {
                ans += (a[v[l].second]+a[v[r].second])/k;
                l++;
                r--;
            }
            else
            {
                long long sum2 = a[v[l].second] + a[v[l+1].second];
                ans += sum2/k;
                l += 2;
            }
        }

        cout<<ans<<endl;





    }
}