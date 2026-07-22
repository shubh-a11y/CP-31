
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long k,x;
        cin>>k>>x;

        if(k*k <= x)
        {
            cout<<2*k-1<<endl;
            continue;
        } 
        else if(k*(k+1) == 2*x)
        {
            cout<<k<<endl;
            continue;
        }
        else if(k*(k+1) > 2*x)
        {
            long long res = 0;
            long long low = 1,high = k;
            while(low <= high)
            {
                long long mid = (low+high)/2;
                if(mid*(mid+1) >= 2*x)
                {
                    res = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            cout<<res<<endl;
            continue;
        }
        else{
            long long rem = x - (k*(k+1))/2;
            long long sum = k*(k-1)/2 - rem;
            long long low = 1,high = k-1;
            long long res = 0;
            while(low <= high)
            {
                long long mid = (low+high)/2;
                if(mid*(mid+1)/2 >= sum)
                {
                    res = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            if(res*(res+1)/2 == sum)
            {
                cout<<k+k-res-1<<endl;
                continue;
            }
            else
            {
                cout<<k+k-res<<endl;
                continue;
            }
        }
    }
}
