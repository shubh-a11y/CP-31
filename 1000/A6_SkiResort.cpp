
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;

    while(t--)
    {
        long long n,k,q;
        cin>>n>>k>>q;

        vector<long long> a(n);
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }

        long long count = 0;
        long long res = 0;
        for(long long i=0;i<n;i++)
        {
            if(a[i] <= q)
            {
                count++;
            }
            else{

                if(count >= k)
                {
                    long long ele = count-k+1;
                    res += (ele*(ele+1))/2;
                }
                count = 0;
            }

        }

        if(count >= k)
        {
            long long ele = count-k+1;
            res += (ele*(ele+1))/2;
        }

        cout<<res<<endl;
    }
}