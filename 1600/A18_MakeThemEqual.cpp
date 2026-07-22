
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<long long> minSteps(1001,INT_MAX);

        minSteps[1] = 0;

        for(int i=1;i<=1000;i++)
        {
            for(int j=1;j<=i;j++)
            {
                int div = i/j;

                if(i + div <= 1000)
                {
                    minSteps[i + div] = min(minSteps[i + div], minSteps[i] + 1);
                }
            }
        }

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<long long> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        vector<long long> c(n);
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }

        k = min(k,12LL*n);

        

        vector<long long> dp(k + 1, 0);
        // Maximum value we can achieve with at most j steps


        for(int i=1;i<=n;i++)
        {
            for(int j=k;j>=0;j--)
            {

                if(j-minSteps[b[i-1]] >= 0)
                {
                    dp[j] = max(dp[j], dp[j-minSteps[b[i-1]]] + c[i-1]);
                }
            }
        }

        long long ans = 0;

        for(int i=0;i<=k;i++)
        {
            ans = max(ans, dp[i]);
        }

        cout<<ans<<endl;

    }
}