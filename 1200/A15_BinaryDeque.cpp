
#include<bits/stdc++.h>
using namespace std;




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;

        vector<int> a(n);
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        int l = 0;
        int r = n-1;

        if(s > sum)
        {
            cout<<-1<<endl;
            continue;
        }
        else if(s == sum)
        {
            cout<<0<<endl;
            continue;
        }
        else{
            
            vector<int> prefix(n);
            prefix[0] = a[0];
            for(int i=1;i<n;i++)
            {
                prefix[i] = prefix[i-1] + a[i];
            }
            int ans = 0;
            int l = -1;
            int r = 0;
            int sum = 0;
            while(r<n)
            {
                sum = prefix[r];
                if(l>=0)
                {
                    sum = prefix[r]-prefix[l];
                }
                while(sum>s)
                {
                    l++;
                    sum = prefix[r]-prefix[l];
                }
                if(sum == s)
                {
                    ans = max(ans,r-l);
                }
                r++;
            }

            cout<<n-ans<<endl;

        }


    }
}