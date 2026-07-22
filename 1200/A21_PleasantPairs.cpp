
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
        vector<vector<long long>> a(n);
        for(int i=0;i<n;i++)
        {
            long long x;
            cin>>x;
            a[i] = {x,i}; // Value, Index;
        }

        sort(a.begin(),a.end());
        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i][0]*a[j][0] >= 2*n)
                {
                    break;
                }
                else
                {
                    if((a[i][0]*a[j][0] == a[i][1]+a[j][1]+2) && (a[i][1] != a[j][1]))
                    {
                        ans++;
                    }
                }
            }
        }

        cout<<ans<<endl;
        

    }
}