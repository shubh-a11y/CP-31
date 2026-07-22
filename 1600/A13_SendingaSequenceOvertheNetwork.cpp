
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
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

        vector<bool> dp(n+1,false); //dp[i] = true, => if everything is possible to be sent till i-1
        dp[0] = true;

        for(int i=0;i<n;i++)
        {
            if (dp[i] == true)
            {
                if (i + a[i] + 1 <= n)
                {
                    dp[i + a[i] + 1] = true;
                }
            }

            if(i-a[i] >= 0)
            {
                if(dp[i-a[i]])
                {
                    dp[i+1] = true;
                }
            }
        }

        if(dp[n])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}