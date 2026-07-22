
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

        unordered_map<long long,long long> mp; //remainder count;
        long long maxX = 0;

        for(int i=0;i<n;i++)
        {
            if(a[i] % k == 0)
            {
                continue; // No remainder, skip
            }
            else
            {
                long long rem = (k-a[i]%k);
                mp[rem]++;
                maxX = max(maxX, rem + (mp[rem]-1)*k);
            }
        }

        if(maxX == 0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<maxX+1<<endl;
        }



    }
}