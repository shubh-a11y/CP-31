
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9+7;
    int t;
    cin>>t;

    // Range of n is 1 to 40000;

    vector<long long> palindromes;

    for(int i=1;i<=40000;i++)
    {
        string s = to_string(i);
        string rev = s;
        reverse(rev.begin(),rev.end());

        if(s == rev)
        {
            palindromes.push_back(i);
        }
    }

    int size = palindromes.size();

    vector<vector<long long>> dp(size+1,vector<long long>(40001,0));
    // dp[i][j] = number of ways to make sum j using first i palindromes;
    for(int i=0;i<=size;i++)
    {
        dp[i][0] = 1;
    }

    for(int i=1;i<=size;i++)
    {
        
        long long palindrome = palindromes[i-1];
        for(int j=1;j<=40000;j++)
        {
            if(j < palindrome)
            {
                dp[i][j] = (dp[i-1][j])%mod;
            }
            else
            {
                dp[i][j] = ((dp[i-1][j])%mod + (dp[i][j-palindrome])%mod)%mod;
            }
        }
    }   
    
    while(t--)
    {
        long long n;
        cin>>n;

        cout<<dp[size][n]<<endl;


    }
}