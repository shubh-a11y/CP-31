
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int chance, int idx, vector<vector<int>> &dp)
{
    int n = a.size();

    if (idx == n)
    {
        return 0;
    }

    if (dp[idx][chance] != -1)
    {
        return dp[idx][chance];
    }

    int ans = INT_MAX;
    if (chance == 0)
    {
        ans = min(ans, a[idx] + solve(a, 1, idx + 1, dp));

        if (idx + 1 < n)
        {
            ans = min(ans, a[idx] + a[idx + 1] + solve(a, 1, idx + 2, dp));
        }

        return dp[idx][chance] = ans;
    }
    else
    {
        ans = min(ans, solve(a, 0, idx + 1, dp));

        if(idx+1 < n)
        {
            ans = min(ans, solve(a, 0, idx + 2, dp));
        }

        return dp[idx][chance] = ans;
    }

    return dp[idx][chance] = ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        vector<vector<int>> dp(n, vector<int>(2, -1));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int chance = 0;
        int idx = 0;

        cout << solve(a, chance, idx,dp) << endl;
    }
}