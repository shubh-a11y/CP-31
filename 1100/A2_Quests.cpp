
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
        vector<int> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        for(int i=1;i<n;i++)
        {
            a[i] = a[i] + a[i-1];
        }

        int res = 0;
        int maxi = 0;
        int ans = 0;

        int iter = min(n-1,k-1);
        for(int i=0;i<=iter;i++)
        {
            res = a[i];
            maxi = max(maxi,b[i]);

            res += (k-i-1)*maxi;
            ans = max(ans,res);
        }

        cout<<ans<<endl;

    }
}