
#include<bits/stdc++.h>
using namespace std;

long long loga(long long val)
{
    if(val == 1)
    {
        return 0;
    }

    long long ans = 0;
    while(val > 1)
    {
        val = val/2;
        ans++;
    }

    return ans;
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
        unordered_map<long long,long long> freq;
        for(int i=0;i<n;i++)
        {
            freq[loga(a[i])]++;
        }

        long long ans = 0;

        for(auto it: freq)
        {
            if(it.second > 1)
            {
                ans += (it.second)*(it.second-1)/2;
            }
        }

        cout<<ans<<endl;


    }
}
