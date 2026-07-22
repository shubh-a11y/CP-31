
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<long long> a(m);
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
        }
        vector<long long> diff;
        sort(a.begin(),a.end());
        for(int i=1;i<m;i++)
        {
            diff.push_back(a[i]-a[i-1]-1);
        }
        diff.push_back(a[0]-1 + n - a[m-1]);

        sort(diff.begin(),diff.end(),greater<long long>());
        long long ans = 0;
        long long div = -4;

       
        for(int i=0;i<diff.size();i++)
        {
            div = div+4;
            if(diff[i]-div <= 0)
            {
                break;
            }
            else if(diff[i]-div <= 2)
            {
                ans++;
            }
            else{
                ans += diff[i]-div-1;
            }

        }

        cout<<n-ans<<endl;

    }
}