#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Fast I/O (helps prevent Time Limit Exceeded on big test cases)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        unordered_map<long long,long long> freq;
        for(int i=0;i<n;i++)
        {
            a[i] = a[i]%m;
            freq[a[i]]++;
        }

        long long ans = 0;
        
        for(auto it: freq)
        {
            long long rem = it.first;
            
            if(freq[rem] == 0) continue; 

            if(rem == 0)
            {
                ans++;
                freq[0] = 0; 
            }
            else if(m%2 == 0 && rem == m/2)
            {
                ans++;
                freq[rem] = 0;
            }
            else
            {
                long long freq1 = freq[rem];
                long long freq2 = 0;
                
                if (freq.count(m - rem)) {
                    freq2 = freq[m - rem];
                }

                if(abs(freq1 - freq2) <= 1)
                {
                    ans++;
                }
                else
                {
                    ans += abs(freq1 - freq2);
                }
                
                freq[rem] = 0;
                if (freq.count(m - rem)) {
                    freq[m - rem] = 0;
                }
            }
        }

        cout<<ans<<"\n";
    }    
    return 0;
}