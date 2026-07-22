
#include <bits/stdc++.h>
using namespace std;

int solve(vector<long long>& a, int curr, int type, vector<vector<long long>>& dp)
{
    int n = a.size();

    if(curr > n-1)
    {
        return 0;
    }
    else if(curr == n-1)
    {
        if((type == 0) && (a[curr] == 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

        if(dp[type][curr] != -1)
        {
            return dp[type][curr];
        }

    if(type == 0)
    {
        if((a[curr] == 0) && (a[curr+1] == 0))
        {
            return dp[type][curr] = min(solve(a, curr+1, 1,dp),solve(a,curr+2,1,dp));
        }
        else if((a[curr] == 0) && (a[curr+1] == 1))
        {
            return dp[type][curr] = min(solve(a, curr+1, 1,dp),1+solve(a,curr+2,1,dp));
        }
        else if((a[curr] == 1) && (a[curr+1] == 0))
        {
            return dp[type][curr] = min(1+solve(a, curr+1, 1,dp),1+solve(a,curr+2,1,dp));
        }
        else
        {
            return dp[type][curr] = min(1+solve(a, curr+1, 1,dp),2+solve(a, curr+2, 1,dp));
        }
    }
    else if(type == 1)
    {
        return dp[type][curr] = min(solve(a, curr+1, 0,dp),solve(a,curr+2,0,dp));
    }


}

int main()
{
    int t;
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

        int curr = 0;
        int type = 0;

        vector<vector<long long>> dp(2, vector<long long>(n, -1));


        cout<<solve(a, curr, type,dp)<<endl;

    }
}