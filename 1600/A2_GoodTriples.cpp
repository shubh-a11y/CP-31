
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

        long long res = 1;

        while(n > 0)
        {
            long long d = n%10;
            res = res * (d+2)*(d+1)/2;
            n = n/10;

        }

        cout<<res<<endl;
    }
}