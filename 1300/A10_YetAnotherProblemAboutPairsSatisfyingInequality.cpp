
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> a(n+1);
        for(int i=0;i<n;i++)
        {
            cin>>a[i+1];
        }

        vector<long long> b(n+1);
        for(int i=1;i<=n;i++)
        {
            if(i > a[i])
            {
                b[i] = a[i];
            }
            else{
                b[i] = 0;
            }
        }

        vector<long long> c(n+1,0);
        for(int i=n;i>0;i--)
        {
            if(b[i] > 0)
            {
                c[b[i]-1]++;
            }
            if(i != n)
            {
                c[i] += c[i+1];
            }
        }

        long long ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i] < i)
            {
                ans += c[i];
            }
        }
        cout<<ans<<endl;
    }
}