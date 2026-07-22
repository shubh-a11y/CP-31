
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<long long> exists(1e6+1, 0);
    for(long long r=2;r<=10000;r++)
    {
         long long rn = (r*r*r);
         long long sum = (rn-1)/(r-1);

         while(sum <= 1e6)
         {
            exists[sum] = 1;
            rn *= r;
            sum = (rn-1)/(r-1);
         }
    }

    while(t--)
    {
        long long n;
        cin>>n;

        if(exists[n] == 1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
}