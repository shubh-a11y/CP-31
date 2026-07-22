
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    const int MOD = 1e9+7;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        long long ans = 1;
        for(int i=0;i<k;i++)
        {
            ans = (ans * n) % MOD;
        }

        cout<<ans<<endl;
    }
}