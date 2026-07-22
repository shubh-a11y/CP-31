#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long mod = 1e9 + 7;
    
    while (t--)
    {
        long long n;
        cin >> n;


        long long n_mod = n % mod;

        long long term1 = n_mod;
        long long term2 = (n_mod + 1) % mod;
        long long term3 = (4 * n_mod - 1) % mod;


        long long ans = (term1 * term2) % mod;
        ans = (ans * term3) % mod;

        long long final_ans = (ans * 337) % mod;

        cout << final_ans << "\n";
    }
}