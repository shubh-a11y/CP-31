
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>b[j];
    }


    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[b[i]] = i;
    }

    int lastidx = -1;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(mp[a[i]] > lastidx)
        {
            lastidx = mp[a[i]];
            ans++;
        }
        
    }

    cout<<n-ans<<endl;



}