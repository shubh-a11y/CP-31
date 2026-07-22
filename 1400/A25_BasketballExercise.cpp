
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& h1, vector<long long>& h2, vector<vector<long long>>& dp, long long idx, int state)
{
    if(idx == h1.size())
    {
        return 0;
    }

    if(dp[idx][state] != 0)
    {
        return dp[idx][state];
    }

    if(state == 1)
    {
        return dp[idx][state] = max(h2[idx] + solve(h1,h2,dp,idx+1,2), solve(h1,h2,dp,idx+1,0));
    }
    else if(state == 2)
    {
        return dp[idx][state] = max(h1[idx] + solve(h1,h2,dp,idx+1,1), solve(h1,h2,dp,idx+1,0));
    }
    else
    {
        return dp[idx][state] = max({h1[idx] + solve(h1,h2,dp,idx+1,1), h2[idx] + solve(h1,h2,dp,idx+1,2), solve(h1,h2,dp,idx+1,0)});
    }



}

int main()
{
    int n;
    cin>>n;

    vector<long long> h1(n);
    vector<long long> h2(n);

    for(int i=0;i<n;i++)
    {
        cin>>h1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>h2[i];
    }

    vector<vector<long long>> dp(n, vector<long long> (3,0));
    long long idx = 0;
    int state = 0; // 0: not taken, 1: taken from h1, 2: taken from h2
    

    long long res = solve(h1,h2,dp,idx,state);
    cout<<res<<endl;
}

