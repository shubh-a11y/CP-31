
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        long long W;
        cin>>W;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        map<long long,long long> mp;
        for(int i=0;i<n;i++)
        {
            long long ele = a[i];
            long long idx = 0;
            while(ele > 0)
            {
                if((ele&1) == 1)
                {
                    mp[idx]++;
                }
                ele = ele>>1;
                idx++;
            }
        }
        
        long long ans = 0;
        long long left = mp.size();

        while(left > 0)
        {
            long long w = W;
            
            for(auto it=mp.rbegin();it!=mp.rend();it++)
            {
                if(w >= 1<<it->first)
                {
                    int num = w/(1<<it->first);

                    if(it->second == 0)
                    {
                        continue;
                    }

                    if(it->second > num)
                    {
                        w = w - num*(1<<it->first);
                        it->second -= num;
                    }
                    else{
                        w = w - it->second*(1<<it->first);
                        it->second = 0;
                        left--;
                    }
                }
                else{
                    continue;
                }
            }
            ans++;
        }

        cout<<ans<<endl;


    }
}

