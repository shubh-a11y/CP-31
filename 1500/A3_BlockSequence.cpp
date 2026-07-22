#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &a, long long curr, vector<long long> &dp, long long ans)
{
    int n = a.size();
    if(curr == n)
    {
        return 0;
    }
    else if(curr > n)
    {
        return INT_MAX;
    }
    
    if(dp[curr] != INT_MAX)
    {
        return dp[curr];
    }

    dp[curr] = min(1+ solve(a,curr+1,dp,ans+1),solve(a,curr+a[curr]+1,dp,ans));
    return dp[curr];
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
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }

        long long ans = 0;
        vector<long long> dp(n,INT_MAX);
        long long curr = 0;
        cout<<solve(a,curr,dp,ans)<<endl;
    }
}