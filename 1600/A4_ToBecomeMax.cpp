
#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> a, long long mid, long long k)
{
    long long n = a.size();
    
    long long req = 0;
    for(int i=0;i<n-1;i++)
    {
        req = 0;
        long long curr = mid;
        for(int j=i;j<n;j++)
        {
            if(a[j] >= curr)
            {
                if(req <= k)
                {
                    return true;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(j == n-1)
                {
                    return false;
                }

                req += curr-a[j];
                curr--;

                if(req > k)
                {
                    break;
                }
            }
        }
    }

    if(req <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<long long> a(n);
        long long maxi = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            maxi = max(maxi, a[i]);
        }

        long long high = maxi+k;
        long long low = maxi;
        
        long long res = maxi;
        while(low <= high)
        {
            long long mid = low + (high-low)/2;

            if(check(a,mid,k))
            {
                res = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        cout<<res<<endl;

    }


}