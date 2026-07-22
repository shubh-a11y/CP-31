
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

        vector<long long> s(n+1);

        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }

        vector<long long> dp(n+1,1); // dp[i] = maximum length of subsequence ending at index i

        for(int i=1;i<=n;i++)
        {
            int multiple = 2;
            for(int j=i*multiple;j<=n;j+=i)
            {
                if(s[j]>s[i])
                {
                    dp[j] = max(dp[j],dp[i]+1);
                }
            }
        }

        long long result = 0;
        for(int i=1;i<=n;i++)
        {
            result = max(result,dp[i]);
        }

        cout<<result<<endl;
    }
}
        