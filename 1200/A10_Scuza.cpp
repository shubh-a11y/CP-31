
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,q;
        cin>>n>>q;
        vector<long long>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<long long> k(q);
        for(int i = 0; i < q; i++)
        {
            cin >> k[i];
        }
        vector<long long> prefix(n);
        prefix[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }

    vector<long long> a2(n);
    a2[0] = a[0];
    for(int i=1;i<n;i++)
    {
        a2[i] = max(a2[i-1],a[i]);
    }

    vector<long long> ans;
    for(int i=0;i<q;i++)
    {
        int idx = upper_bound(a2.begin(),a2.end(),k[i]) - a2.begin();
        if (idx == 0)
        {
            ans.push_back(0);
        }
        else{
            ans.push_back(prefix[idx-1]);
        }
    }

    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    }

 




}