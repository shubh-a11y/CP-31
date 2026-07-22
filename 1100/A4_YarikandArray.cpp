
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<long long> prefix(n,0);
        prefix[0] = a[0];

        for(int i=1;i<n;i++)
        {
            if(prefix[i-1] < 0)
            {
                prefix[i] = a[i];
            }
            else
            {
                if((a[i]^a[i-1]) % 2 != 0) // odd even or even odd
                {
                    prefix[i] = prefix[i-1] + a[i];
                }
                else
                {
                    prefix[i] = a[i];
                }
            }
            
        }
        long long res = prefix[0];
        for(int i=1;i<n;i++)
        {
            res = max(res,prefix[i]);
        }

        cout<<res<<endl;
    }
}