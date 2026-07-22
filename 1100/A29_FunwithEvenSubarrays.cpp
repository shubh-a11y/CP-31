
#include<bits/stdc++.h>
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

        long long ans = 0;
        long long count = 1;

        int i = n-2;
        while(i >= 0)
        {
            if(a[i] != a[i+1])
            {
                ans++;
                count = n-i-1;
                while(count > 0 && i >= 0)
                {
                    a[i] = a[i+1];
                    count--;
                    i--;
                }
            }
            else
            {
                i--;
            }
        }

        cout<<ans<<endl;

    }
}