
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;

        vector<long long> f(n);
        vector<long long> c(m);
        for(int i=0;i<n;i++)
        {
            cin>>f[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>c[i];
        }

        sort(f.begin(),f.end(),greater<long long>());

        int curr = 0;
        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            if(curr < (f[i]-1))
            {
                ans += c[curr];
                curr++;
            }
            else
            {
                ans += c[f[i]-1];
            }
        }

        cout<<ans<<endl;
    }
}
