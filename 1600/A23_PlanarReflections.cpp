
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
        // dp[i][j] = number of particles created by a particle with age j and i planes ahead of it;

        for(int i=0;i<=n;i++)
        {
            dp[i][1] = 1; 
        }

        for(int i=0;i<=k;i++)
        {
            dp[0][i] = 1;
        }

        for(int j=2;j<=k;j++)
        {
            for(int i=1;i<=n;i++)
            {
                dp[i][j] = (dp[i-1][j] + dp[n-i][j-1]) % mod;
            }
        }

        cout<<dp[n][k]<<endl;
    }
}