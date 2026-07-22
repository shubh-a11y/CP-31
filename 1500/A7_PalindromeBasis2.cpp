

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

    vector<long long> dp(40001,0);
    // dp[0] = number of ways to make sum 0 using any number of palindromes is 1 (by choosing nothing);
        dp[0] = 1;
    

    for(int i=1;i<=size;i++)
    {
        
        long long palindrome = palindromes[i-1];
        for(int j=palindrome;j<=40000;j++)
        {
            dp[j] = ((dp[j])%mod + (dp[j-palindrome])%mod)%mod;
        }
    }   
    
    while(t--)
    {
        long long n;
        cin>>n;

        cout<<dp[n]<<endl;


    }
}