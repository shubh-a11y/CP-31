
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long w,h;
        cin>>w>>h;

        long long k1,k2;
        cin>>k1;
        vector<long long> x1(k1);
        for(long long i=0;i<k1;i++)
        {
            cin>>x1[i];
        }
        cin>>k2;
        vector<long long> x2(k2);
        for(long long i=0;i<k2;i++)
        {
            cin>>x2[i];
        }

        long long k3,k4;
        cin>>k3;
        vector<long long> y1(k3);
        for(long long i=0;i<k3;i++)
        {
            cin>>y1[i];
        }
        cin>>k4;
        vector<long long> y2(k4);
        for(long long i=0;i<k4;i++)
        {
            cin>>y2[i];
        }

        long long max_width_x = max(x1[k1-1] - x1[0],x2[k2-1] - x2[0]);
        long long max_width_y = max(y1[k3-1] - y1[0],y2[k4-1] - y2[0]);

        long long ans = max(max_width_x * h, max_width_y * w);
        cout<<ans<<endl;
    }

}