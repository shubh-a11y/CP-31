
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        long long nums = (n/k)*2;
        long long ans = 0;

        for(int i=0;i<(k)/2;i++)
        {
            unordered_map<char,long long> freq;
            long long maxfreq = 0;
            for(int j=i;j<n;j+=k)
            {
                freq[s[j]]++;
                maxfreq = max(maxfreq,freq[s[j]]);

            }
            for(int j=k-1-i;j<n;j+=k)
            {
                freq[s[j]]++;
                maxfreq = max(maxfreq,freq[s[j]]);
            }
            ans += nums - maxfreq;
        }

        if(k%2 == 1)
        {
            unordered_map<char,long long> freq;
            long long maxfreq = 0;
            for(int j=(k)/2;j<n;j+=k)
            {
                freq[s[j]]++;
                maxfreq = max(maxfreq,freq[s[j]]);

            }
            ans += (n/k) - maxfreq;
        }

        cout<<ans<<endl;


    }
}