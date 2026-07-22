
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<long long> a;
        for(int i=0;i<n;i++)
        {
            long long x;
            cin>>x;
            a.push_back(x);
        }

        if(k>2)
        {
            cout<<0<<endl;
            continue;
        }

        sort(a.begin(), a.end());
        long long min_ele = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            min_ele = min(min_ele, (long long)a[i]);
        }

        if (k == 1)
        {
            long long minDiff = LLONG_MAX;
            for (int i = 1; i < n; i++)
            {
                minDiff = min(minDiff, (long long)(a[i] - a[i - 1]));
            }

            long long res = min(minDiff, min_ele);

            cout<<res<<endl;
            continue;
        }
        else if(k == 2)
        {   
            long long ans = min_ele;

            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    long long diff = abs(a[j] - a[i]);
                    int low_idx = lower_bound(a.begin(), a.end(), diff) - a.begin();

                    ans = min(ans, diff);

                    if(low_idx < n)
                    {
                        ans = min(ans, abs(a[low_idx] - diff));
                    }
                    if(low_idx > 0)
                    {
                        ans = min(ans, abs(a[low_idx - 1] - diff));
                    }
                }
            }

            cout<<ans<<endl;
            continue;

        }
    }
}