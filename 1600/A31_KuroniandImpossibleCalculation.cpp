
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if(n > m)
    {
        cout<<0<<endl;
    }
    else
    {
        long long ans = 1;

        sort(a.begin(),a.end());

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans = (ans*(a[j]-a[i]))%m;
            }
        }

        cout<<ans<<endl;
    }





}