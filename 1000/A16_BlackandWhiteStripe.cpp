
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;

        vector<char> a(n);
        for(long long i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int count = 0;
        vector<int> prefix(n,0);

        for(int i=0;i<n;i++)
        {
            if(a[i] == 'W')
            {
                count++;
            }
            prefix[i] = count;
        }

        int ans = n;
        ans = min(ans,prefix[k-1]);
        for(int i=0;i+k<n;i++)
        {
            ans = min(ans,prefix[i+k]-prefix[i]);
        }

        cout<<ans<<endl;
    }
}