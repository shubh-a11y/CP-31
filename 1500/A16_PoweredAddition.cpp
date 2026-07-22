
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

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        long long ans = 0;
        long long maxi = a[0];

        for(int i=1;i<n;i++)
        {
            if(a[i] < maxi)
            {
                long long diff = maxi - a[i];
                long long power = 0;
                long long temp = 1;
                while(temp < diff+1)
                {
                    temp *= 2;
                    power++;
                }
                ans = max(ans,power);
            
            }
            else
            {
                maxi = a[i];
            }
        }

        cout<<ans<<endl;
    }
}