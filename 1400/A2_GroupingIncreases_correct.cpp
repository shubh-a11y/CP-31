
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

        vector<int> a(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int ans = 0;
        int x = INT_MAX;
        int y = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if((a[i] <= x) && (a[i] <= y))
            {
                if(x <= y)
                {
                    x = a[i];
                }
                else{
                    y = a[i];
                }
            }
            else if(a[i] <= x)
            {
                x = a[i];
            }
            else if(a[i] <= y)
            {
                y = a[i];
            }
            else{
                ans++;
                if(x <= y)
                {
                    x = a[i];
                }
                else{
                    y = a[i];
                }
            }
        }

        cout<<ans<<endl;
    }
}