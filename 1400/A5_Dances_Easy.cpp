
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int> a(n);
        a[0] = 1;
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
        }
        vector<int> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int ans = 0;

        int a_idx = 0;
        int b_idx = 0;
        while(b_idx < n)
        {
            if(a[a_idx] >= b[b_idx])
            {
                ans++;
                b_idx++;
            }
            else
            {
                a_idx++;
                b_idx++;
            }
        }
        cout<<ans<<endl;

    }
}