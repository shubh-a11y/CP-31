
#include <bits/stdc++.h>
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

        vector<vector<long long>> dp(n+1, vector<long long>(2));

        // dp[idx][chance] = minimum cost from idx to the end given that it is chance's turn
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i][0] = a[i] + dp[i+1][1];

            if(i+2 <= n)
            {
                dp[i][0] = min(dp[i][0], a[i] + a[i+1] + dp[i+2][1]);
            }

            dp[i][1] = dp[i+1][0];

            if(i+2 <= n)
            {
                dp[i][1] = min(dp[i][1], dp[i+2][0]);
            }
        
        }

        cout<<dp[0][0]<<endl;

    }
}