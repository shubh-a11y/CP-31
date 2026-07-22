
#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long factorial(long long curr)
{
    if(curr == 0 || curr == 1)
    {
        return 1;
    }
    long long ans = 1;
    for(int i=2;i<=curr;i++)
    {
        ans = ((ans%MOD) * (i))%MOD;
    }
    return ans;
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        long long minOps = 0;
        long long seqs = 1;

        int n = s.length();
        long long curr = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i] != s[i-1])
            {
                if(curr > 1)
                {
                    minOps += curr-1;
                    seqs = ((seqs) % MOD * (curr) % MOD) % MOD;
                    curr = 1;


                }
                else{
                    continue;
                }

            }
            else{
                curr++;
            }
        }

        if (curr > 1)
        {
            minOps += curr - 1;
            seqs = ((seqs) % MOD * (curr) % MOD) % MOD;
            curr = 1;
        }

        seqs = (seqs * (factorial(minOps)))%MOD;

        cout<<minOps<<" "<<seqs<<endl;
    }
}