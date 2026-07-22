
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        map<long long,long long> freq;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }

        vector<long long> dist;
        for(auto it:freq)
        {
            dist.push_back(it.first);
        }
        sort(dist.begin(),dist.end());

        long long ans = 0;
        long long curr = freq[dist[0]];
        for(int i=1;i<dist.size();i++)
        {
            if(dist[i] == dist[i-1]+1)
            {
                if (freq[dist[i]] < curr)
                {
                    ans += curr - freq[dist[i]];
                    curr = freq[dist[i]];
                }
                else{
                    curr = freq[dist[i]];
                }
            }
            else{
                ans += curr;
                curr = freq[dist[i]];
            }

        }

        ans += curr;

        cout<<ans<<endl;

    }
}