
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,x,m;
        cin>>n>>x>>m;

        long long l = x;
        long long r = x;

        for(int i=0;i<m;i++)
        {
            long long a,b;
            cin>>a>>b;

            if(a > r || b < l)
            {
                continue;
            }
            else
            {
                l = min(l,a);
                r = max(r,b);
            }
        }
        cout<<(r-l+1)<<endl;
    
    }
}