
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

        long long ans = 0;

        long long div = 1;
        while(div <= n)
        {
            ans += n/div;
            div *= 2;
        }
        cout<<ans<<endl;
    }
}