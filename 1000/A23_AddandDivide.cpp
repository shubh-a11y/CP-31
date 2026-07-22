
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long a,b;
        cin>>a>>b;

        long long ans = LLONG_MAX;

        for(int i=b;i<=b+36;i++)
        {
            if(i == 1)
            {
                continue;
            }
            long long curr = i-b;
            long long dummy = a;

            while(dummy > 0)
            {
                dummy /= i;
                curr++;
            }
            ans = min(ans,curr);
        }

        cout<<ans<<endl;
    }
}