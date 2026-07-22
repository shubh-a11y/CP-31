
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;

    vector<vector<long long>> dp(k+1, vector<long long>(n+1, 0)); // k = length of array, n = last number

    long long mod = 1e9+7;
    for(int i=1;i<=n;i++)
    {
        dp[1][i] = 1; // Base case: there's one way to have an array of length 1 with last number i
    }

    for(int i=2;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int x=1;x<=sqrt(j);x++)
            {
                if(j % x == 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][x])%mod; // If x is a divisor of j, we can append j to an array ending with x
                    if(x != j / x) // If x and j/x are different, we can also append j to an array ending with j/x
                    {
                        dp[i][j] = (dp[i][j] + dp[i-1][j / x])%mod;
                    }
                }
            }
        }
    }
    
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = (ans + dp[k][i])%mod; // Sum up all arrays of length k with last number i
    }
    cout<<ans<<endl;
}