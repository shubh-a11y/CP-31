
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    vector<vector<long long>> a(2023,vector<long long>(2023,0));

    int num = 1;
    for(int i=0;i<2023;i++)
    {
        for(int j=0;j<=i;j++)
        {
            a[i][j] = num++;
        }
    }

    vector<vector<long long>> dp(2023,vector<long long>(2023,0));

    dp[0][0] = 1;

    for(int i=1;i<2023;i++)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j] = a[i][j]*a[i][j];

            dp[i][j] += dp[i-1][j];

            if(j > 0)
            {
                dp[i][j] = dp[i][j] + dp[i-1][j-1];

                if(i-2 >= 0)
                {
                    dp[i][j] = dp[i][j] - dp[i-2][j-1];
                }
            }
        }
    }

    while(t--)
    {
        long long n;
        cin>>n;

        if(n == 1)
        {
            cout<<1<<endl;
            continue;
        }

        long long low = 1;
        long long high = 2023;
        long long row = -1;
        while(low <= high)
        {
            long long mid = low + (high-low)/2;

            if(mid*(mid+1)/2 >= n)
            {
                high = mid-1;
            }
            else
            {
                row = mid;
                low = mid+1;
            }
        }

        long long col = n-(row*(row+1)/2);
        col--;

        long long ans = dp[row][col];

        cout<<ans<<endl;
    }
}