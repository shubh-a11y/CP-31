
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,x;
        cin>>n>>x;
        vector<long long> a(n);
        long long low = LLONG_MAX;
        long long high = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            low = min(low,a[i]);
            high = max(high,a[i]);
        }

        high += x;
        
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;

            long long water = 0;
            for(int i=0;i<n;i++)
            {
                if(a[i] < mid)
                {
                    water += (mid - a[i]);
                }
            }

            if(water <= x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout<<high<<endl;

    }
}