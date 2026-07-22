
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<long long> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<long long> diff(n);

        for(int i=0;i<n;i++)
        {
            diff[i] = b[i]-a[i];
        }
        long long ans = 0;

        sort(diff.begin(),diff.end());
        int l=0;
        int r = n-1;

        while(l<r)
        {
            if(diff[l] + diff[r] >= 0)
            {
                ans++;
                l++;
                r--;
            }
            else if(diff[l] + diff[r] < 0)
            {
                l++;
            }

        }

        cout<<ans<<endl;
    }

}