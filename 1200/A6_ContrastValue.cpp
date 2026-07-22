
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long n;
        cin>>n;

        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }

        vector<long long> dist;

        dist.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i] != a[i-1])
            {
                dist.push_back(a[i]);
            }
        }

        if(dist.size() == 1)
        {
            cout<<1<<endl;
            continue;
        }
        bool flag = true;
        if(dist[1] < dist[0])
        {
            flag = false;
        }
        int ans = 1;
        for(int i=2;i<dist.size();i++)
        {
            if(flag && dist[i] < dist[i-1])
            {
                ans++;
                flag = false;
            }
            else if(!flag && dist[i] > dist[i-1])
            {
                ans++;
                flag = true;
            }
        }

        cout<<ans+1<<endl;
    }
}