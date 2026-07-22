
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

        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int ele = a[i];
            int idx = 0;
            while(ele > 0)
            {
                if(ele&1 == 1)
                {
                    mp[idx]++;
                }
                ele = ele>>1;
                idx++;
            }
        }

        int hcf = 0;
        for(auto it:mp)
        {
            hcf = __gcd(hcf,it.second);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(hcf%i == 0)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}